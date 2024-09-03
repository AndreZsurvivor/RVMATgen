// Utilities.cpp
#include "RVMATgen.h"

namespace rvmatGen
{
    std::mutex cout_mutex;
    std::mutex queue_mutex;

    namespace GUI
    {
        void HelpMarker(const char* description)
        {
            ImGui::TextDisabled("*");
            if (ImGui::IsItemHovered())
            {
                ImGui::BeginTooltip();
                ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                ImGui::TextUnformatted(description);
                ImGui::PopTextWrapPos();
                ImGui::EndTooltip();
            }
        }

        void PlusMinusRGB(std::string name, ImVec4& rgba_vector)
        {
            std::string minus = " -  ##";
            std::string plus = " + ##";
            ImGui::SameLine(); ImGui::Text("RGB");
            ImGui::SameLine();
            bool minus_clicked = false;
            std::string buttonMinus = minus + name;
            if (ImGui::Button(buttonMinus.c_str()))
                minus_clicked = true;
            if (minus_clicked)
            {
                rgba_vector.x = rgba_vector.x - 0.01f; rgba_vector.y = rgba_vector.y - 0.01f; rgba_vector.z = rgba_vector.z - 0.01f;
            }
            ImGui::SameLine();
            bool plus_clicked = false;
            std::string buttonPlus = plus + name;
            if (ImGui::Button(buttonPlus.c_str()))
                plus_clicked = true;
            if (plus_clicked)
            {
                rgba_vector.x = rgba_vector.x + 0.01f; rgba_vector.y = rgba_vector.y + 0.01f; rgba_vector.z = rgba_vector.z + 0.01f;
            }
        }
    }

    bool pathIsValid(const std::string& path)
    {
        std::filesystem::path fsPath(path);
        return std::filesystem::exists(fsPath) && std::filesystem::is_directory(fsPath);
    }
    bool isValidImagetopaaExe(const std::string& path)
    {
        std::filesystem::path fsPath(path);
        return std::filesystem::exists(fsPath) &&
            std::filesystem::is_regular_file(fsPath) &&
            fsPath.filename() == "ImageToPAA.exe";
    }
    std::string quoteString(const std::string& str) {
        if (str.find(' ') != std::string::npos) {
            return "\"" + str + "\"";
        }
        return str;
    }
    
    std::vector<const char*> findAndCopyStrings(const std::vector<std::string>& input, const std::string& token)
    {
        std::vector<const char*> result;

        for (const auto& str : input) {
            if (str.find(token) != std::string::npos) {
                result.push_back(str.c_str());
            }
        }

        return result;
    }

    int runImageToPAA(const std::string& exePath, const std::string& source, const std::string& destination, int size)
    {
        std::ostringstream command;
        command << rvmatGen::quoteString(exePath) << " ";

        if (size > 0) {
            command << "-size=" << size << " ";
        }

        command << rvmatGen::quoteString(source);

        if (!destination.empty()) {
            command << " " << rvmatGen::quoteString(destination);
        }

        std::cout << "Executing command: " << command.str() << std::endl;
        return std::system(command.str().c_str());
    }

    void convertImage(const std::string& exePath, const std::filesystem::path& inputFile, const std::filesystem::path& outputDir) {
        std::filesystem::path outputFile = outputDir / inputFile.filename().replace_extension(".paa");

        std::string command = quoteString(exePath) + " " +
            quoteString(inputFile.string()) + " " +
            quoteString(outputFile.string());

        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << "Executing: " << command << std::endl;
        }

        int result = std::system(command.c_str());

        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            if (result == 0) {
                std::cout << "Successfully converted: " << inputFile << std::endl;
            }
            else {
                std::cout << "Failed to convert: " << inputFile << " (Error code: " << result << ")" << std::endl;
            }
        }
    }

    void workerThread(const std::string& exePath, const std::filesystem::path& outputDir,
        std::queue<std::filesystem::path>& workQueue) {
        while (true) {
            std::filesystem::path inputFile;
            {
                std::lock_guard<std::mutex> lock(queue_mutex);
                if (workQueue.empty()) {
                    break;
                }
                inputFile = workQueue.front();
                workQueue.pop();
            }
            convertImage(exePath, inputFile, outputDir);
        }
    }

    void convertImagesInParallel(const std::string& exePath, const std::string& inputDir, const std::string& outputDir) {
        std::queue<std::filesystem::path> workQueue;
        for (const auto& entry : std::filesystem::directory_iterator(inputDir)) {
            if (entry.is_regular_file() && (entry.path().extension() == ".png" || entry.path().extension() == ".jpg")) {
                workQueue.push(entry.path());
            }
        }

        unsigned int threadCount = std::thread::hardware_concurrency();
        threadCount = threadCount == 0 ? 4 : threadCount; // Use 4 threads if we can't detect core count

        std::vector<std::thread> threads;
        for (unsigned int i = 0; i < threadCount; ++i) {
            threads.emplace_back(workerThread, exePath, outputDir, std::ref(workQueue));
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }
}