void uppercase(std::string output) {
    std::string input;
    std::getline(std::cin, input);

    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 'a' + 'A';
        }
    }

    std::ofstream outputFile(output);
    outputFile << input;
    outputFile.close();
}