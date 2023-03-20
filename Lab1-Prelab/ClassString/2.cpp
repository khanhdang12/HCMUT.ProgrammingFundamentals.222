void findAllIndex(string s1, string s2) {
    int index = s1.find(s2);
    while (index != string::npos) {
        cout << index << " ";
        index = s1.find(s2, index + 1);
    }
    if (s1.find(s2) == string::npos) {
        cout << -1;
    }
}
//This code is incorrect, only passed 90% testcases.