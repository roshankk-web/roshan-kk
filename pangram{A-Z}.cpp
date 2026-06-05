
int main() {
    string str;
    cin >> str;
    getline(cin, str);

    long long flag = 0;
    int flag = 0;

    for(char ch : str) {
        if(ch >= 'A' && ch <= 'Z') {
            flag |= (1LL << (ch - 'A'));
    for (char ch : str) {
        if (ch >= 'A' && ch <= 'Z') {
            flag |= (1 << (ch - 'A'));
        }
        else if(ch >= 'a' && ch <= 'z') {
            flag |= (1LL << (26 + ch - 'a'));
        else if (ch >= 'a' && ch <= 'z') {
            flag |= (1 << (ch - 'a'));
        }
    }

    long long allChars = (1LL << 52) - 1;

    cout << (flag == allChars ? "Yes" : "No");
    cout << (flag == (1 << 26) - 1 ? "Yes" : "No");

    return 0;
}
