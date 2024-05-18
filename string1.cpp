#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct word {
    string data;
    int fre;
};

// Hàm so sánh để sắp xếp các từ theo số lần xuất hiện giảm dần, nếu bằng nhau thì theo thứ tự từ điển
bool compare(word a, word b) {
    if (a.fre == b.fre) {
        return a.data < b.data;
    } else {
        return a.fre > b.fre;
    }
}

int main() {
    const int max_words = 1000;
    word words[max_words];
    int index = 0;
    
    string line, word;
    
    // Đọc và xử lý đầu vào
    while (getline(cin, line)) {
        stringstream ss(line);
        while (ss >> word) {
            // Tìm từ này trong mảng
            bool found = false;
            for (int i = 0; i < index; ++i) {
                if (words[i].data == word) {
                    words[i].fre++;
                    found = true;
                    break;
                }
            }
            // Nếu không tìm thấy thì thêm từ vào mảng
            if (!found) {
                words[index].data = word;
                words[index].fre = 1;
                index++;
            }
        }
    }
    
    // Sắp xếp mảng theo số lần xuất hiện giảm dần và theo thứ tự từ điển
    sort(words, words + index, compare);
    
    // In ra từ xuất hiện nhiều nhất
    if (index > 0) {
        cout << words[0].data << endl;
    }
    
    return 0;
}
