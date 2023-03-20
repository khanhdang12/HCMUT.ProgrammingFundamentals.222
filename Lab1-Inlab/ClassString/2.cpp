void deleteWord(string s, string s1)
{
    size_t pos = 0;
    while ((pos = s.find(s1, pos)) != std::string::npos) 
    {
        s.erase(pos, s1.length());
    }
    cout << s << endl;
}