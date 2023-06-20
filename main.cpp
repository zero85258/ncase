#include <iostream>
#include <string>
#include <algorithm>

enum class CaseType {
    Snake,
    Camel,
    Kebab
};

// 將字串轉換為蛇形命名法
std::string toSnakeCase(const std::string& input) {
    std::string output = input;
    std::replace(output.begin(), output.end(), ' ', '_');
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;
}

// 將字串轉換為駝峰命名法
std::string toCamelCase(const std::string& input) {
    std::string output = input;
    bool capitalizeNext = false;
    output.erase(std::remove(output.begin(), output.end(), ' '), output.end());
    for (char& c : output) {
        if (c == '_') {
            capitalizeNext = true;
        } else if (capitalizeNext) {
            c = ::toupper(c);
            capitalizeNext = false;
        }
    }
    return output;
}

// 將字串轉換為烤串命名法
std::string toKebabCase(const std::string& input) {
    std::string output = input;
    std::replace(output.begin(), output.end(), ' ', '-');
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;
}

// 解析命令列參數
CaseType parseArguments(int argc, char* argv[]) {
    if (argc == 2) {
        std::string arg(argv[1]);
        if (arg == "--snake") {
            return CaseType::Snake;
        } else if (arg == "--camel") {
            return CaseType::Camel;
        } else if (arg == "--kebab") {
            return CaseType::Kebab;
        }
    }
    // 預設為蛇形命名法
    return CaseType::Snake;
}

int main(int argc, char* argv[]) {
    // 解析命令列參數
    CaseType caseType = parseArguments(argc, argv);

    std::string input;
    std::getline(std::cin, input);

    // 進行命名案例轉換
    std::string output;
    switch (caseType) {
        case CaseType::Snake:
            output = toSnakeCase(input);
            break;
        case CaseType::Camel:
            output = toCamelCase(input);
            break;
        case CaseType::Kebab:
            output = toKebabCase(input);
            break;
    }

    // 輸出結果
    std::cout << output << std::endl;

    return 0;
}
