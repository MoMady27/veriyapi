#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Node sınıfı, bağlı liste için kullanılacak temel düğüm yapısı
class Node {
public:
    int data; // Veri taşıyan değişken
    Node* next; // Sonraki düğümü işaret eden gösterici

    Node(int d) : data(d), next(nullptr) {} // Yapıcı fonksiyon
};

// Yığın (Stack) sınıfı
class Stack {
private:
    Node* top; // Yığının en üstündeki düğüm

public:
    Stack() : top(nullptr) {} // Yapıcı fonksiyon

    // Yığına eleman ekleme
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // Yığından eleman çıkarma
    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        else {
            cout << "Yigin bos." << endl;
        }
    }

    // Yığını temizleme
    void clear() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Yıkıcı fonksiyon
    ~Stack() {
        clear();
    }

    // Yığının en üstündeki elemanı gösterme
    void peek() {
        if (top != nullptr) {
            cout << "Yiginıin en ustundeki eleman: " << top->data << endl;
        }
        else {
            cout << "Yigin bos." << endl;
        }
    }

    // Yığının içeriğini yazdırma
    void display() {
        Node* current = top;
        cout << "Yigin: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Yığındaki eleman sayısını gösterme
    int size() {
        int count = 0;
        Node* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

};

// Kuyruk (Queue) sınıfı
class Queue {
private:
    Node* front; // Kuyruğun başındaki düğüm
    Node* rear;  // Kuyruğun sonundaki düğüm

public:
    Queue() : front(nullptr), rear(nullptr) {} // Yapıcı fonksiyon
    //front ve rear nullptr (bos gosterici) olarak baslar

    // Kuyruğa eleman ekleme
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear != nullptr) { 
            rear->next = newNode;
        }
        rear = newNode;
        if (front == nullptr) {
            front = rear;
        }
    }

    // Kuyruktan eleman çıkarma
    void dequeue() {
        if (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
        else {
            cout << "Kuyruk bos." <<endl;
        }
    }
    // Kuyruğu temizleme
    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    // Yıkıcı fonksiyon
    ~Queue() {
        clear();
    }
    

    // Kuyruğun başındaki elemanı gösterme
    void peek() {
        if (front != nullptr) {
            cout << "Kuyrugun basindaki eleman: " << front->data <<endl;
        }
        else {
            cout << "Kuyruk bos." <<endl;
        }
    }

    // Kuyruğun içeriğini yazdırma
    void display() {
        Node* current = front;
        cout << "Kuyruk: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }
    // Kuyruktaki eleman sayısını gösterme
    int size() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Tek Yönlü Bağlı Liste (Singly Linked List) sınıfı
class SinglyLinkedList {
private:
    Node* head; // Listenin başındaki düğüm

public:
    SinglyLinkedList() : head(nullptr) {} // Yapıcı fonksiyon

    // Listeye eleman ekleme (araya ekleme)
    void insertAfter(int prevData, int data) {
        Node* current = head;
        while (current != nullptr && current->data != prevData) {
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node(data);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Listeye eleman ekleme (sona ekleme)
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Listeden eleman silme
    void removeold(int data) {
        if (head == nullptr) return;
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->data != data) {
                current = current->next;
            }
            if (current->next != nullptr) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }

    // Listeden eleman silme (aradan silme)
    void remove(int data) {
        if (head == nullptr) return;
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->data != data) {
                current = current->next;
            }
            if (current->next != nullptr) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }

    // Listeden eleman silme (sondan silme)
    void removeEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

  

    // Listeyi temizleme
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    // Listenin içeriğini yazdırma
    void display() {
        Node* current = head;
        cout << "Bagli Liste: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }

    // Eleman sayısını döndürme
    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// İkili Ağaç Düğümü (Binary Tree Node) sınıfı
class TreeNode {
public:
    int data; // Veri taşıyan değişken
    TreeNode* left; // Sol çocuk düğümü işaret eden gösterici
    TreeNode* right; // Sağ çocuk düğümü işaret eden gösterici

    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {} // Yapıcı fonksiyon
};

// İkili Ağaç (Binary Tree) sınıfı
class BinaryTree {
private:
    TreeNode* root; // Ağacın kök düğümü

    // İkili ağaç düğümüne ekleme (yardımcı fonksiyon)
    void insert(TreeNode*& node, int data) {
        if (node == nullptr) {
            node = new TreeNode(data);
        }
        else if (data < node->data) {
            insert(node->left, data);
        }
        else {
            insert(node->right, data);
        }
    }

    // İkili ağacı dolaşma (yardımcı fonksiyon)
    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // İkili ağacı dolaşma (PreOrder)
    void preorder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // İkili ağacı dolaşma (PostOrder)
    void postorder(TreeNode* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    // Düğümü silme (yardımcı fonksiyon)
    TreeNode* remove(TreeNode* node, int data) {
        if (node == nullptr) {
            return node;
        }

        //Bu, BST'nin özelliğidir: sol çocuklar kök düğümden küçüktür, sağ çocuklar ise büyüktür.

        if (data < node->data) { //Silinmek istenen veri (data)
            node->left = remove(node->left, data);
        }
        else if (data > node->data) {
            node->right = remove(node->right, data);
        }
        else {
            // 1. Durum: Yaprak düğüm (çocuksuz)
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // 2. Durum: Tek çocuklu düğüm
            else if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // 3. Durum: İki çocuklu düğüm
            else {
                TreeNode* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }


    // Ağacı temizleme (yardımcı fonksiyon)
    void clear(TreeNode*& node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }

    // Ağacın eleman sayısını hesaplama (yardımcı fonksiyon)
    int countNodes(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

public:
    BinaryTree() : root(nullptr) {} // Yapıcı fonksiyon

    // Ağaca eleman ekleme
    void insert(int data) {
        insert(root, data);
    }

    // Ağacı dolaşma (inorder)
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Ağacı dolaşma (preorder)
    void preorder() {
        preorder(root);
        cout << endl;
    }

    // Ağacı dolaşma (postorder)
    void postorder() {
        postorder(root);
        cout << endl;
    }

    // Ağacı temizleme
    void clear() {
        clear(root);
    }

    // Ağacın eleman sayısını döndürme
    int countNodes() {
        return countNodes(root);
    }
};

// Çırpılama Tablosu (Hash Table) sınıfı
class HashTable {
private:
    vector<int> table; // Hash tablosunu temsil eden vektör
    int size; // Tablonun boyutu

    // Basit bir hash fonksiyonu
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size, -1); // Tablonun başlangıçta boş olması için -1 ile doldurulur
    }

    // Tabloda bir anahtar ekleme
    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {
            index = (index + 1) % size; // Lineer yer değiştirme
        }
        table[index] = key;
    }

    // Tablodan bir anahtar silme
    void remove(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (index + 1) % size;
        }
        cout << "Eleman bulunamadi." << endl;
    }

    // Tabloyu temizleme
    void clear() {
        fill(table.begin(), table.end(), -1);
    }

    // Tablodaki eleman sayısını gösterme
    int count() {
        int cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
                ++cnt;
            }
        }
        return cnt;
    }

    // Tabloyu yazdırma
    void display() {
        cout << "Hash Table: ";
        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
                cout << table[i] << " ";
            }
            else {
                cout << "- ";
            }
        }
        cout << endl;
    }
};
// Ana program
int main() {
    int choice;
    Stack stack;
    Queue queue;
    SinglyLinkedList linkedList;
    BinaryTree binaryTree;
    HashTable hashTable(10); // Boyutu 10 olan bir hash tablosu

    do {
        // Ana menüyü göster
        cout << "1. Yigin Uygulamasi\n";
        cout << "2. Kuyruk Uygulamasi\n";
        cout << "3. Bagli Liste Uygulamasi\n";
        cout << "4. Ikili Agac Uygulamasi\n";
        cout << "5. Cirpilama Uygulamasi\n";
        cout << "6. Programdan Cik\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Yığın menüsü
            int stackChoice;
            do {
                cout << "1. Yigina Eleman Ekle\n";
                cout << "2. Yigindan Eleman Cikar\n";
                cout << "3. Yigini temizle\n";
                cout << "4. Yiginin En Ustundeki Elemanu Goster\n";
                cout << "5. Yigini Goster\n";
                cout << "6. Yigini eleman sayilarini Goster\n";
                cout << "7. Ana Menuye Don\n";
                cout << "Seciminiz: ";
                cin >> stackChoice;
                switch (stackChoice) {
                case 1:
                    int stackData;
                    cout << "Eklenecek eleman: ";
                    cin >> stackData;
                    stack.push(stackData);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.clear();
                    break;
                case 4:
                    stack.peek();
                    break;
                case 5:
                    stack.display();
                    break;
                case 6:
                    stack.size();
                    cout << "Yigindaki eleman sayisi: " << stack.size() << endl;
                    break;
                }
            } while (stackChoice != 5);
            break;
        }
        case 2: {
            // Kuyruk menüsü
            int queueChoice;
            do {
                cout << "1. Kuyruga Eleman Ekle\n";
                cout << "2. Kuyruktan Eleman Cikar\n";
                cout << "3. Kuyrugu temizle\n";
                cout << "4. Kuyrugun Basindaki Elemani Goster\n";
                cout << "5. Kuyrugu Goster\n";
                cout << "6. Kuyruktaki Eleman Sayisini Goster\n";
                cout << "7. Ana Menuye Don\n";
                cout << "Seciminiz: ";
                cin >> queueChoice;
                switch (queueChoice) {
                case 1:
                    int queueData;
                    cout << "Eklenecek eleman: ";
                    cin >> queueData;
                    queue.enqueue(queueData);
                    break;
                case 2:
                    queue.dequeue();
                    break;
                case 3:
                    queue.clear();
                    break;
                case 4:
                    queue.peek();
                    break;
                case 5:
                    queue.display();
                    break;
                case 6:
                    queue.size();
                    cout << "Kuyruktaki eleman sayisi: " << queue.size() << endl;
                    break;
                }
            } while (queueChoice != 5);
            break;
        }
        case 3:
            // Bağlı Liste menüsü
            int listChoice;
            do {
                cout << "1. Listeye Eleman Ekle\n";
                cout << "2. Listeden Eleman Sil\n";
                cout << "3. Listeyi temizle\n";
                cout << "4. Listeyi elemanlari Goster\n";
                cout << "5. Listeyi eleman sayisini Goster\n";
                cout << "6. Ana Menuye Don\n";
                cout << "Seciminiz: ";
                cin >> listChoice;
                switch (listChoice)
                {
                case 1:
                {
                    int addChoice;
                    int value;
                    int data;
                    int prevData = 0;
                    cout << "Ekleme türünü seçiniz:\n";
                    cout << "1- Basa eleman ekle\n";
                    cout << "2- Sona eleman ekle\n";
                    cout << "3- Liste işlemlerine geri dön\n";
                    cout << "Seçiminiz: ";
                    cin >> addChoice;

                    if (addChoice == 1) {
                        cout << "Eklenecek eleman: ";
                        cin >> data;
                        linkedList.insertAfter(prevData, data);
                    }

                    else if (addChoice == 2) {
                        int data;
                        cout << "Eklenecek eleman: ";
                        cin >> data;
                        linkedList.append(data);
                    }
                    else if (addChoice == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Gecersiz secim!" << endl;
                    }
                    break;
                    
                }

                case 2: {
                    int addChoice;
                    do {
                        cout << "Ekleme türünü seçiniz:\n";
                        cout << "1- Basatan eleman silme\n";
                        cout << "2- Sondan eleman silme\n";
                        cout << "3- Liste işlemlerine geri dön\n";
                        cout << "Seçiminiz: ";
                        cin >> addChoice;
                        switch (addChoice) {
                        case 1: {
                            int prevData, data;
                            cout << "Hangi elemandan sonra eklemek istersiniz? ";
                            cin >> prevData;
                            cout << "Eklenecek eleman: ";
                            cin >> data;
                            linkedList.insertAfter(prevData, data);
                            break;
                        }
                        case 2: {
                            int data;
                            cout << "Eklenecek eleman: ";
                            cin >> data;
                            linkedList.append(data);
                            break;
                        }
                        }
                    } while (addChoice != 3);
                    break;
                }
                case 3:
                    linkedList.clear();
                    break;
                case 4:
                    linkedList.display();
                    break;
                case 5:
                    linkedList.size();
                    cout << "Listedeki eleman sayisi: " << linkedList.size() << endl;
                    break;

                }
            } while (listChoice != 4);
            break;

        case 4: {
            // İkili Ağaç menüsü
            int treeChoice;
            do {
                cout << "1. Agaca Eleman Ekle\n";
                cout << "2. Agaci Eleman Sil\n";
                cout << "3. Agaci Temizle\n";
                cout << "4. Agactaki Eleman Sayisini Goster\n";
                cout << "5. Agaci InOrder dolasarak elemanlari Goster\n";
                cout << "6. Agaci PreOrder dolasarak elemanlari Goster\n";
                cout << "7. Agaci PostOrder dolasarak elemanlari Goster\n";
                cout << "8. Ana Menuye Don\n";
                cout << "Seciminiz: ";
                cin >> treeChoice;
                switch (treeChoice) {
                case 1:
                    int treeData;
                    cout << "Eklenecek eleman: ";
                    cin >> treeData;
                    binaryTree.insert(treeData);
                    break;
                case 2:
                    cout << "Agac (Inorder): ";
                    binaryTree.inorder();
                    break;
                case 3:
                    binaryTree.clear();
                    cout << "Agac temizlendi.\n";
                    break;
                case 4:
                    cout << "Agactaki eleman sayisi: " << binaryTree.countNodes() << endl;
                    break;
                case 5:
                    cout << "Agac (Inorder): ";
                    binaryTree.inorder();
                    break;
                case 6:
                    cout << "Agac (PreOrder): ";
                    binaryTree.preorder();
                    break;
                case 7:
                    cout << "Agac (PostOrder): ";
                    binaryTree.postorder();
                    break;
                }
            } while (treeChoice != 8);
            break;
        }
        case 5: {
            // Çırpılama menüsü
            int hashChoice;
            do {
                cout << "\nHash Tablosu Menusu:\n";
                cout << "1. Hash Tablosuna Eleman Ekle\n";
                cout << "2. Hash Tablosundan Eleman Sil\n";
                cout << "3. Hash Tablosunu Temizle\n";
                cout << "4. Hash Tablosundaki Eleman Sayisini Goster\n";
                cout << "5. Hash Tablosundaki Elemanlari Goster\n";
                cout << "6. Ana Menuye Don\n";
                cout << "Seciminiz: ";
                cin >> hashChoice;

                switch (hashChoice) {
                case 1: {
                    int hashData;
                    cout << "Eklenecek eleman: ";
                    cin >> hashData;
                    hashTable.insert(hashData);
                    break;
                }
                case 2: {
                    int hashData;
                    cout << "Silinecek eleman: ";
                    cin >> hashData;
                    hashTable.remove(hashData);
                    break;
                }
                case 3: {
                    hashTable.clear();
                    cout << "Hash Tablosu temizlendi." << endl;
                    break;
                }
                case 4: {
                    cout << "Hash Tablosundaki eleman sayisi: " << hashTable.count() << endl;
                    break;
                }
                case 5: {
                    hashTable.display();
                    break;
                }
                case 6:
                    cout << "Ana menuye donuluyor..." << endl;
                    // Burada ana menüye dönmek için ek bir kod yazabilirsiniz.
                    break;
       
                default:
                    cout << "Gecersiz secim. Tekrar deneyin." << endl;
                    break;
                }
            } while (hashChoice != 6);
            break;
        }
        case 6:
            cout << "Programdan cikiliyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}