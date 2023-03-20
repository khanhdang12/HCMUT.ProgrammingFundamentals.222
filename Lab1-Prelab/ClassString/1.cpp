void cutString(string s, int index)
{
    int len = s.length();
    if (index < len) {
        string s1 = s.substr(index , len - index);
        cout << s1 << endl;
    }
}
