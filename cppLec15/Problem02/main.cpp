#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

typedef struct book {
    string title;
    string author;
    set<int> edition;
} book;

int find_quotation(string str) {
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 0x22) count++;
        if(count == 2) return i;    // return the second 0x22 position
    }
    return 0;
}



int main() {
    
    set<string> Title;
    set<string> Author;
    vector<book> data;
    
    string one_line;
    
    while(getline(cin, one_line)) {
        
        if(one_line.substr(0, 6) == "Insert") {
            string title = "", author = "";
            int edition = 0;
            
            if(one_line.length() > 7) {
                one_line.erase(0, 7);   // Insert_ を消去
                
                int pos = find_quotation(one_line);
                if(pos != 0) {
                    title = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                    title.pop_back();   //最後の0x22消去
                    title.erase(0, 1);   //最初の0x22消去
                    
                    if(one_line.length() > (3+title.length())) {
                        one_line.erase(0, 3+title.length());   // "title"_ を消去
                        pos = find_quotation(one_line);
                        if(pos != 0) {
                            author = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                            author.pop_back();   //最後の0x22消去
                            author.erase(0, 1);   //最初の0x22消去
                            
                            if(one_line.length() > (3+author.length())) {
                                one_line.erase(0, 3+author.length());   // "author"_ を消去
                                if(!one_line.empty()) {
                                    edition = stoi(one_line);
                                }
                                else {
                                    // "edition"に問題あり
                                    cout << "Incomplete Command." << endl;
                                    continue;
                                }
                            }
                            else {
                                // "author"後に問題あり
                                cout << "Incomplete Command." << endl;
                                continue;
                            }
                        }
                        else {
                            // "author"に問題あり
                            cout << "Incomplete Command." << endl;
                            continue;
                        }
                    }
                    else {
                        // "title"後に問題あり
                        cout << "Incomplete Command." << endl;
                        continue;
                    }
                }
                else {
                    // "title"に問題あり
                    cout << "Incomplete Command." << endl;
                    continue;
                }
            }
            else {
                // Insert後に問題あり
                cout << "Incomplete Command." << endl;
                continue;
            }
            
            if(title == "" && author == "" && edition == 0) exit(EXIT_FAILURE);
            else {
                if(Title.find(title) != Title.end() && Author.find(author) != Author.end()) {
                    for(int i = 0; i < data.size(); i++) {
                        if(data[i].title == title && data[i].author == author) {
                            if(data[i].edition.find(edition) != data[i].edition.end()) {
                                cout << "Datum already exist." << endl;
                            }
                            else {
                                cout << "Insert " << author << "\'s " << title << ", Edition: " << edition << "." << endl;
                                data[i].edition.insert(edition);
                            }
                            break;
                        }
                    }
                }
                else {
                    cout << "Insert " << author << "\'s " << title << ", Edition: " << edition << "." << endl;
                    book new_book;
                    new_book.title = title;
                    new_book.author = author;
                    new_book.edition.insert(edition);
                    data.push_back(new_book);
                    Title.insert(title);
                    Author.insert(author);
                }
            }
        }
        else if(one_line.substr(0, 14) == "Delete Edition") {
            string title = "", author = "";
            int edition = 0;
            
            if(one_line.length() > 15) {
                one_line.erase(0, 15);   // Deleta_Edition_ を消去
                
                int pos = find_quotation(one_line);
                if(pos != 0) {
                    title = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                    title.pop_back();   //最後の0x22消去
                    title.erase(0, 1);   //最初の0x22消去
                    
                    if(one_line.length() > (3+title.length())) {
                        one_line.erase(0, 3+title.length());   // "title"_ を消去
                        pos = find_quotation(one_line);
                        if(pos != 0) {
                            author = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                            author.pop_back();   //最後の0x22消去
                            author.erase(0, 1);   //最初の0x22消去
                            
                            if(one_line.length() > (3+author.length())) {
                                one_line.erase(0, 3+author.length());   // "author"_ を消去
                                if(!one_line.empty()) {
                                    edition = stoi(one_line);
                                }
                                else {
                                    // "edition"に問題あり
                                    cout << "Incomplete Command." << endl;
                                    continue;
                                }
                            }
                            else {
                                // "author"後に問題あり
                                cout << "Incomplete Command." << endl;
                                continue;
                            }
                        }
                        else {
                            // "author"に問題あり
                            cout << "Incomplete Command." << endl;
                            continue;
                        }
                    }
                    else {
                        // "title"後に問題あり
                        cout << "Incomplete Command." << endl;
                        continue;
                    }
                }
                else {
                    // "title"に問題あり
                    cout << "Incomplete Command." << endl;
                    continue;
                }
            }
            else {
                // Delete_Edition後に問題あり
                cout << "Incomplete Command." << endl;
                continue;
            }
            
            if(title == "" && author == "" && edition == 0) exit(EXIT_FAILURE);
            else {
                if(Title.find(title) != Title.end() && Author.find(author) != Author.end()) {
                    for(int i = 0; i < data.size(); i++) {
                        if(data[i].title == title && data[i].author == author) {
                            if(data[i].edition.find(edition) != data[i].edition.end()) {
                                cout << "Delete " << author << "\'s " << title << ", Edition: " << edition << "." << endl;
                                data[i].edition.erase(edition);
                                if(data[i].edition.empty()) {
                                    data.erase(data.begin()+i);
                                    Title.erase(title);
                                    Author.erase(author);
                                }
                            }
                            else {
                                cout << "Datum doesn't exist." << endl;
                            }
                            break;
                        }
                    }
                }
                else {
                    cout << "Datum doesn't exist." << endl;
                }
            }
        }
        else if(one_line.substr(0, 11) == "Delete Book") {
            string title, author;
            
            if(one_line.length() > 12) {
                one_line.erase(0, 12);   // Deleta_Book_ を消去
                
                int pos = find_quotation(one_line);
                if(pos != 0) {
                    title = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                    title.pop_back();   //最後の0x22消去
                    title.erase(0, 1);   //最初の0x22消去
                    
                    if(one_line.length() > (3+title.length())) {
                        one_line.erase(0, 3+title.length());   // "title"_ を消去
                        pos = find_quotation(one_line);
                        if(pos != 0) {
                            author = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                            author.pop_back();   //最後の0x22消去
                            author.erase(0, 1);   //最初の0x22消去
                        }
                        else {
                            // "author"に問題あり
                            cout << "Incomplete Command." << endl;
                            continue;
                        }
                    }
                    else {
                        // "title"後に問題あり
                        cout << "Incomplete Command." << endl;
                        continue;
                    }
                }
                else {
                    // "title"に問題あり
                    cout << "Incomplete Command." << endl;
                    continue;
                }
            }
            else {
                // Delete_Book後に問題あり
                cout << "Incomplete Command." << endl;
                continue;
            }
            
            if(title == "" && author == "") exit(EXIT_FAILURE);
            else {
                if(Title.find(title) != Title.end() && Author.find(author) != Author.end()) {
                    for(int i = 0; i < data.size(); i++) {
                        if(data[i].title == title && data[i].author == author) {
                            for(auto it = data[i].edition.begin(); it != data[i].edition.end(); it++) {
                                cout << "Delete " << author << "\'s " << title << ". Edition: " << *it << "." << endl;
                            }
                            data.erase(data.begin()+i);
                            Title.erase(title);
                            Author.erase(author);
                            break;
                        }
                    }
                }
                else {
                    cout << "Book doesn't exist." << endl;
                }
            }
        }
        else if(one_line.substr(0, 9) == "Find Book") {
            string title, author;
            
            if(one_line.length() > 10) {
                one_line.erase(0, 10);   // Find_Book_ を消去
                
                int pos = find_quotation(one_line);
                if(pos != 0) {
                    title = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                    title.pop_back();   //最後の0x22消去
                    title.erase(0, 1);   //最初の0x22消去
                    
                    if(one_line.length() > (3+title.length())) {
                        one_line.erase(0, 3+title.length());   // "title"_ を消去
                        pos = find_quotation(one_line);
                        if(pos != 0) {
                            author = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                            author.pop_back();   //最後の0x22消去
                            author.erase(0, 1);   //最初の0x22消去
                        }
                        else {
                            // "author"に問題あり
                            cout << "Incomplete Command." << endl;
                            continue;
                        }
                    }
                    else {
                        // "title"後に問題あり
                        cout << "Incomplete Command." << endl;
                        continue;
                    }
                }
                else {
                    // "title"に問題あり
                    cout << "Incomplete Command." << endl;
                    continue;
                }
            }
            else {
                // Find_Book後に問題あり
                cout << "Incomplete Command." << endl;
                continue;
            }
            
            if(title == "" && author == "") exit(EXIT_FAILURE);
            else {
                if(Title.find(title) != Title.end() && Author.find(author) != Author.end()) {
                    for(int i = 0; i < data.size(); i++) {
                        if(data[i].title == title && data[i].author == author) {
                            cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
                            auto it_end = data[i].edition.end();
                            it_end--;
                            for(auto it = data[i].edition.begin(); it != data[i].edition.end(); it++) {
                                cout << *it;
                                if(it != it_end) cout << ", ";
                            }
                            cout << endl;
                            break;
                        }
                    }
                }
                else {
                    cout << "Book doesn't exist." << endl;
                }
            }
        }
        else if(one_line.substr(0, 11) == "Find Author") {
            string author;
            
            if(one_line.length() > 12) {
                one_line.erase(0, 12);   // Find_Author_ を消去
                
                int pos = find_quotation(one_line);
                if(pos != 0) {
                    author = one_line.substr(0, pos+1);    // 最初と最後の0x22ごとsubstr
                    author.pop_back();   //最後の0x22消去
                    author.erase(0, 1);   //最初の0x22消去
                }
                else {
                    // "author"に問題あり
                    cout << "Incomplete Command." << endl;
                    continue;
                }
            }
            else {
                // Find_Author後に問題あり
                cout << "Incomplete Command." << endl;
                continue;
            }
            
            if(author == "") exit(EXIT_FAILURE);
            else {
                if(Author.find(author) != Author.end()) {
                    set<string> find_book;
                    for(int i = 0; i < data.size(); i++) {
                        if(data[i].author == author) {
                            find_book.insert(data[i].title);
                        }
                    }
                    
                    cout << author << "\'s Books: ";
                    auto it_end = find_book.end();
                    it_end--;
                    for(auto it = find_book.begin(); it != find_book.end(); it++) {
                        cout << *it;
                        if(it != it_end) cout << ", ";
                    }
                    cout << endl;
                }
                else {
                    cout << "No book found." << endl;
                }
            }
        }
        else if(one_line.substr(0, 13) == "Sort by Title") {
            set<string> find_author;
            for(auto it_title = Title.begin(); it_title != Title.end(); it_title++) {
                for(int i = 0; i < data.size(); i++) {
                    if(data[i].title == *it_title) {
                        find_author.insert(data[i].author);
                    }
                }
                for(auto it_author = find_author.begin(); it_author != find_author.end(); it_author++) {
                    for(int i = 0; i < data.size(); i++) {
                        if(data[i].title == *it_title && data[i].author == *it_author) {
                            auto it_end = data[i].edition.end();
                            it_end--;
                            cout << "Title: " << *it_title << "\tAuthor: " << *it_author << "\tEdition: ";
                            for(auto it_edi = data[i].edition.begin(); it_edi != data[i].edition.end(); it_edi++) {
                                cout << *it_edi;
                                if(it_edi != it_end) cout << ", ";
                            }
                            cout << endl;
                        }
                    }
                }
            }
        }
        else if(one_line.substr(0, 14) == "Sort by Author") {
            set<string> find_title;
            for(auto it_author = Author.begin(); it_author != Author.end(); it_author++) {
                for(int i = 0; i < data.size(); i++) {
                    if(data[i].author == *it_author) {
                        find_title.insert(data[i].title);
                    }
                }
                for(auto it_title = find_title.begin(); it_title != find_title.end(); it_title++) {
                    for(int i = 0; i < data.size(); i++) {
                        if(data[i].title == *it_title && data[i].author == *it_author) {
                            auto it_end = data[i].edition.end();
                            it_end--;
                            cout << "Title: " << *it_title << "\tAuthor: " << *it_author << "\tEdition: ";
                            for(auto it_edi = data[i].edition.begin(); it_edi != data[i].edition.end(); it_edi++) {
                                cout << *it_edi;
                                if(it_edi != it_end) cout << ", ";
                            }
                            cout << endl;
                        }
                    }
                }
            }
        }
        else {
            cout << "Unknown Command." << endl;
        }
        
    }
    return 0;
}

/*
Insert "Harry" "JK" 1
Insert "Harry" "JK" 1
Insert "Rapunzel" "Unknown" 1812
Insert "Momotaro" "Unknown" 17
Insert "Harry" "JK" 2
Insert "Harry" "JK" 4
Insert "Rapunzel" "Glen Keane" 2010
Find Book "Harry" "JK"
Find Author "Unknown"
Sort by Title
Find Author "KK"
Delete Edition "Harry" "JK" 3
Delete Book "Mamamia" "ABBA"
Delete Edition "Harry" "JK" 1
Delete Book "Rapunzel" "Glen Keane"
Sort by Author
insert
Insert 5

*/
