/*
    1: hàm tạo node mới
    2: chèn đầu 
    3: chèn cuối 
    4: xắp xếp
    5: xóa => xóa theo ten, xóa vị trí, xóa giá trị ( < , > , ==)
    6: tìm kieemd theo tên
    8: dao nguoc ds


*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct sinhVien{
    string name;
    int age;
    sinhVien* next;
};
typedef struct sinhVien* sv;
// =========HÀM TẠO 1 SINH VIÊN MỚI=============
sv taoSv(string name, int age){
    sv newSv=new sinhVien;
    newSv->name=name;
    newSv->age=age;
    newSv->next=NULL;
    return newSv;
}

// =========HÀM THÊM 1 SINH VIÊN VÀO ĐẦU DANH SÁCH=============
void chenDau(sv &head, string name, int age){
    sv newSv=taoSv(name, age);
    if(head==NULL) {
        head=newSv;
    }
    else{
        newSv->next=head;
        head=newSv;
    }
}

// =========HÀM THÊM 1 SINH VIÊN VÀO CUỐI DANH SÁCH=============
void chenCuoi(sv &head, string name, int age){
    sv newSv=taoSv(name,age);
    if(head==NULL){
        head=newSv;
    }
    else{
        sv p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newSv;
    }
}

// HÀM ĐIỀU KIỆN SO SÁNH
bool compare(sv a, sv b){
    if(a->age==b->age) {
        return a->name<b->name;
    }
    else{
        return a->age<b->age;
    }
}
// Hàm xắp xếp sinh viên theo tuổi, nếu tuổi bằng nhau thì xắp xếp theo tên
void xapXep(sv& head, int& cnt) {
    if (cnt == 0) {
        cout << "No students to sort." << endl;
        return;
    }

    sv temp = head;
    sv* studentArray = new sv[cnt];// khai báo 1 mảng động
    int i = 0;
    // Đẩy node sinh vien vào mảng để sapx xếp
    while (temp != NULL) {
        studentArray[i++] = temp;
        temp = temp->next;
    }

    sort(studentArray, studentArray + cnt, compare);
    // day cac node vao lai danh sach lien ket
    head = studentArray[0];
    temp = head;
    for (int i = 1; i < cnt; ++i) {
        temp->next = studentArray[i];
        temp = temp->next;
    }
    temp->next = NULL;

    delete[] studentArray;
}

// HÀM XÓA SV Ở VỊ TRÍ P;
void xoa1(sv &head, int p){
    if(head==NULL){
        return;
    }
    else if(p==1){
        sv temp=head;
        head=temp->next;
        delete temp;

    }
    else{
        int cnt=1;
        sv current=head;
        while(cnt<p-1 && current->next!=NULL){
            cnt++;
            current=current->next;
        }
        sv temp=current->next;
        current->next=temp->next;
        delete temp;


    }

}

// HÀM XÓA SV CÓ TÊN S;
void xoa2(sv &head, string s) {
    if (head == NULL) {
        return;
    }
    else {
        sv pre = NULL;
        sv current = head;
        
        // Loop through the list
        while (current != NULL) {
            // If the current node's name matches s
            if (current->name == s) {
                // If the current node is the head
                if (pre == NULL) {
                    head = current->next; // Update head to the next node
                    delete current; // Delete the current node
                    current = head; // Move to the next node
                }
                else {
                    pre->next = current->next; // Update previous node's next pointer
                    delete current; // Delete the current node
                    current = pre->next; // Move to the next node
                }
            }
            else {
                pre = current; // Move pre pointer to current node
                current = current->next; // Move current pointer to next node
            }
        }
    }
}


// HÀM XÓA TẤT CẢ SV CÓ TUỔI <18;
void xoa3(sv &head){
    if(head==NULL){
        return;
    }
    else{
        sv p=head;
        sv pre=NULL; 
        while(p!=NULL){
            if(p->age<18){
                if(pre==NULL){// neu node xoa nam o vi tri dau tien
                    head=p->next;
                    delete p;
                    p=head;
                } 
                else{
                    pre->next=p->next;
                    delete p;
                    p=pre->next;
                }
            }
            else{
                pre=p;
                p=p->next;
            }
        }

    }
}

// HÀM TÌM KIẾM SINH VIEN THEO TÊN
sv timKiem(sv &head, string s){
    sv current=head;
    while(current!=NULL){
        if(current->name==s){
            return current;
        }
        current=current->next;
    }
    return NULL;
    
}

// HÀM ĐẢO NGƯỢC DANH SÁCH
void daoNguoc(sv &head){
    sv pre=NULL;
    sv current =head;
    sv next=NULL;
    while(current!=NULL){
        next=current->next; // Lưu lại con trỏ đến phần tử tiếp theo của current
        current->next = pre; // Đảo ngược liên kết của current
        pre = current; // Di chuyển prev sang current
        current = next; // Di chuyển current sang phần tử tiếp theo
    }
    head = pre; // prev là phần tử đầu mới của danh sách đảo ngược

}
// Ham chen 1 sinh vien vao truoc vi tri p
void chen1(sv &head, string name, int age, int p) {
    sv newNode = taoSv(name, age);
    if (p == 1 || head == NULL) { // Insert at the beginning
        newNode->next = head;
        head = newNode;
    } else {
        sv current = head;
        int cnt = 1;
        while (cnt < p - 1 && current->next != NULL) {
            cnt++;
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Ham chen 1 sinh vien vao sau  vi tri p

void chen2(sv &head, string name, int age, int p) {
    sv newNode = taoSv(name, age);
    if(newNode == NULL){
        cout << "Khong the tao sinh vien moi\n";
        return;
    }
    
    
    if (p == 1 ) { 
        sv current=head;
        newNode->next=current->next;
        current->next = newNode;
    } 
    else {
        sv current = head;
        int cnt = 1;
        while (cnt < p && current->next != NULL) {
            cnt++;
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


// =========HÀM IN DANH SÁCH SINH VIÊN =============
void in(sv head){
    int cnt=0;
    sv p1=head;
    sv p2=head;
    while(p1!=NULL){
        cnt++;
        p1=p1->next;
    }
    if(cnt==0){
        cout<<"Danh sach rong"<<"\n";
    }
    else{
        p2 = head; 
        while(p2!=NULL){ 
            cout<<p2->name<<" "<<p2->age<<"\n";
            p2=p2->next;
        }
    }
}

int main(){
    int cnt=0;
    sv head=NULL;
    string lc;
    while(cin>>lc){
        if(lc=="end"){
            break;
        }
        if(lc=="in"){
            in(head);
        }
        if(lc=="chendau"){
            cnt++;
            string name;
            cout<<"Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Nhap tuoi sinh vien: ";
            int age;cin>>age;
            chenDau(head,name,age);
        }
        if(lc=="chencuoi"){
            cnt++;
            string name;
            cout<<"Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Nhap tuoi sinh vien: ";
            int age;cin>>age;
            chenCuoi(head,name,age);
        }
        if(lc=="xapxep"){
            xapXep(head,cnt);
        }
        if(lc=="xoa1"){
            int p;cin>>p;
            xoa1(head,p);
        }
        if(lc=="xoa2"){
            string s;
            cout<<"Nhap ten sinh vien can xao: ";
            cin.ignore();
            getline(cin,s);
            xoa2(head,s);
        }
        if(lc=="xoa3"){
            xoa3(head);
        }
        if(lc=="timkiem"){
            string s;
            cout<<"Nhap ten can tim kiem: ";
            cin.ignore();
            getline(cin,s);
            sv target=timKiem(head,s);
            if(target!=NULL){
                cout<<target->name<<" "<<target->age<<"\n";
            }
            else{
                cout<<"Khong tim thay sinh vien: "<<"\n";
            }
        }
        if(lc=="daonguoc"){
            daoNguoc(head);
        }
        if(lc=="chen1"){
            string name;
            cout<<"Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Nhap tuoi sinh vien: ";
            int age;cin>>age;
            int p;
            cout<<"Nhap vi tri can chen: ";
            cin>>p;
            chen1(head,name,age,p);
        }
        if(lc=="chen2"){
            string name;
            cout<<"Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Nhap tuoi sinh vien: ";
            int age;cin>>age;
            int p;
            cout<<"Nhap vi tri can chen: ";
            cin>>p;
            chen2(head,name,age,p);
        }
    }
}