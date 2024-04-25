#include <iostream>
#include <string>
using namespace std;

// Print array elements
void in(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] <<" ";
    }
}

// Delete element from array
void del(int a[], int &n, int k){
    int index = -1; // Initialize with invalid index
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            index = i;
            break;
        }
    }
    if(index != -1){ // Check if element found
        for(int i = index; i < n - 1; i++){
            a[i] = a[i + 1];
        }
        n--;
    }
}

// Insert element at the beginning of array
void insertFirst(int a[], int &n, int k){
    for(int i = n; i > 0; i--){
        a[i] = a[i - 1];
    }
    a[0] = k;
    n++;
}

// Insert element at the end of array
void insertLast(int a[], int &n, int k){
    a[n] = k;
    n++;
}
// inset element having value k at index i in array
void insertHard(int a[], int &n, int index, int value){
    for(int i = n - 1; i >= index; i--){
        a[i + 1] = a[i];
    }
    a[index] = value;
    n++;
}


int main(){
    int n;
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    string lc;
    cout << "Nhap lua chon : ";
    while(cin >> lc){
        
        if(lc == "end"){
            break;
        }
        if(lc == "xoa"){
            cout << "Nhap phan tu can xoa: ";
            int k;
            cin >> k;
            del(a, n, k);
            cout << "Mang sau khi xoa: ";
            in(a, n);
            cout << endl;
        }
        if(lc == "chendau"){
            int t;
            cout << "Nhap phan tu can chen dau: ";
            cin >> t;
            insertFirst(a, n, t);
            in(a, n);
            cout << endl;
        }
        if(lc == "chencuoi"){
            int x;
            cout << "Nhap phan tu can chen cuoi: ";
            cin >> x;
            insertLast(a, n, x);
            in(a, n);
            cout << endl;
        }
        if(lc=="chenkho"){
            int value;
            cout<<"nhap gia tri can chen: ";
            cin >> value;
            int index;
            cout<<"Nhap chi so muon chen k vao: ";
            cin>>index;
            insertHard(a,n,index,value);
            cout << "Mang sau khi chen : ";
            in(a,n);
            cout<<"\n";
        }
        cout << "Nhap lua chon : ";
        
    }
    return 0;
}
