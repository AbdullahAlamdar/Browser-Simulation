#include <iostream>
#include <cstdlib> 
using namespace std;
void openHtmlFile(const std::string& filePath);
class node{
    public:
    string url;
    int visitCount;
    node*next;  
    node(string url){
        this->url=url;
        visitCount=0;
        next=NULL;  
    }
};
class linkedList{
    public:
    node*head;
    node*tail;
    node*current;
    linkedList(){
        head=NULL;
        tail=NULL;
        current=NULL;
    }
    void addNode(const string& url) {
        node* newNode = new node(url);
        newNode->visitCount+=1;
        node* temp = head;

        while (temp != nullptr) {
            if (temp->url == url) {
                temp->visitCount++;
                delete newNode;
                clearForwardHistory();
                current = temp;
                return;
            }
            temp = temp->next;
        }
        if (head == NULL) {
            head = tail = current = newNode;
        } else {
            clearForwardHistory();
            current->next = newNode;  
            current = newNode;
            tail = newNode;
        }
        cout << "Visited: " << current->url <<endl;
    }
    
    void moveBack(int steps){
        if (current == head) {
            cout << "Already at the first URL." << endl;
            return;
        }
        node* temp = head;
        while (temp != NULL && temp->next != current) {
            temp = temp->next;
        }
        while(steps > 0 && temp != NULL) {
            current = temp;
            steps--;
            temp = head;
            while (temp != NULL && temp->next != current) {
                temp = temp->next;
            }
        }
        cout<<"Moved back to : "<<current->url<<endl;
        openHtmlFile(current->url);
    }

    void moveForward(int steps){
        while(steps > 0 && current->next != NULL){
            current = current->next;
            steps--;
        }
        cout<<"Moved forward to : "<<current->url<<endl;
        openHtmlFile(current->url);
    }

    void clearForwardHistory(){
        node*temp = current->next;
        while(temp != NULL){
            node*next = temp->next;
            delete temp;
            temp = next;
        }
        current->next = NULL;
        tail = current;
    }

    string getCurrentUrl(){
        if(current){
            return current->url;
        }
        else{
            cout<<"NO such url"<<endl;
            return "";
        }
    }

    string mostVisited(){
        node* temp = head;
        int max = -1;
        string most_visited;
        while(temp != NULL){
            if(temp->visitCount > max){
                max = temp->visitCount;
            }
            temp = temp->next;
        }
        node*temp2 = head;
        while(temp2 != NULL){
            if(temp2->visitCount == max){
                most_visited = temp2->url;
            }
            temp2 = temp2->next;
        }
        return most_visited;
    }

    void sortNodesByVisitCount() {
        if (head == nullptr || head->next == nullptr) {
            return; 
        }

        node* currentNode;
        bool swapped = true;

        while (swapped) {
            swapped = false; 
            currentNode = head;

            while (currentNode->next != nullptr) {
              
                if (currentNode->visitCount < currentNode->next->visitCount) {
                    string tempUrl = currentNode->url;
                    int tempVisitCount = currentNode->visitCount;

                    currentNode->url = currentNode->next->url;
                    currentNode->visitCount = currentNode->next->visitCount;

                    currentNode->next->url = tempUrl;
                    currentNode->next->visitCount = tempVisitCount;

                    swapped = true;  
                }
                currentNode = currentNode->next;
            }
        }
    }

    void display(){
        node*temp = head;
        while(temp != NULL){
            cout << temp->url << endl;
            temp = temp->next;
        }
    }
};

class BrowserHistory{
    public:
    linkedList history;

    void visitUrl(string url){
        history.addNode(url);
        openHtmlFile(url);
        cout<<"Url visited : "<<url<<endl;
    }

    void back(int steps){
        history.moveBack(steps);
        cout<<"Moved back to steps : "<<steps<<" to url : "<<history.getCurrentUrl()<<endl;
    }

    void forward(int steps){
        history.moveForward(steps);
        cout<<"Moved forward to steps : "<<steps<<" to url : "<<history.getCurrentUrl()<<endl;
    }

    string most_visited(){
        string mv = history.mostVisited();
        return mv;
    }

    void sort(){
        history.sortNodesByVisitCount();
    }

    void disp(){
        history.display();
    }
};

void openHtmlFile(const std::string& filePath) {
#ifdef _WIN32
    std::string command = "start " + filePath;
#elif __linux__
    std::string command = "xdg-open " + filePath;
#elif __APPLE__
    std::string command = "open " + filePath;
#else
    std::cerr << "Unsupported operating system" << std::endl;
    return;
#endif
    std::system(command.c_str());
}

int main() {
    BrowserHistory A;

    string url;
    cout << "Enter the 1st URL to visit : ";
    cin >> url;
    A.visitUrl(url);

    cout << "Enter the 2nd URL to visit : ";
    cin >> url;
    A.visitUrl(url);

    cout << "Enter the 3rd URL to visit : ";
    cin >> url;
    A.visitUrl(url);

    cout << "Enter the 4th URL to visit : ";
    cin >> url;
    A.visitUrl(url);

    int steps;
    cout << "Enter the number of steps to move back : ";
    cin >> steps;
    A.back(steps);

    cout << "Enter the number of steps to move forward : ";
    cin >> steps; 
    A.forward(steps);

    cout << "The most visited site is : " << A.most_visited() << endl;
    A.sort();
    A.disp();

    return 0;
}

