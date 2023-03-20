void replaceString(string s, string s1, string s2)
{
    size_t found = s.rfind(s1); 
    if (found != string::npos) {
        s.replace(found, s1.length(), s2); 
    }
    cout << s << endl; 
}
