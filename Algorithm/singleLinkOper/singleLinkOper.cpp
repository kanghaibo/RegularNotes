#include <iostream>
#include <string>

#define data_type char
using namespace std;

// 建立单链表结构
class singleLink{
  public:
      singleLink() = default;
      data_type ctr;
      singleLink* next; // 指向下一个指针
      ~singleLink();
};
singleLink::~singleLink(){
   ctr = NULL;
   next = NULL;
}
// 初始化头节点
singleLink* initSingleLink(){
  singleLink *head = new singleLink(); // 动态申请空间，堆内存
  head->next = NULL;
  return head;
}

// 头插法插入生成链表
singleLink* insertHead(singleLink *head,const string &str){
  if(str.size() == 0)
    return head;
  for(int i = 0; i<str.size();i++){
    singleLink *pstr = new singleLink();
    pstr->ctr = str[i];
    pstr->next = head;
    head = pstr;
  }
  return head;
}

// 尾插法插入生成链表
singleLink* insertRail(singleLink *head,const string &str){
  if(str.size() == 0)
      return head;
  for(int i = 0; i<str.size();i++){
    singleLink *pstr = new singleLink();
    pstr->ctr = str[i];
    auto tmp = head;
    while(tmp->next){
      tmp = tmp->next;
    }
    tmp->next = pstr;
  }
  return head;
}

// 插入到某个位置
bool insertElement(singleLink *head, int n, data_type elem){
    if(n<0)
      return false;
    int i = 0;
    while(i<n&&head->next){ // 假设没有合适的位置，直接在尾部插入
      head = head->next;
      i++;
    }
    singleLink *pelem = new singleLink();
    pelem->next = head->next;
    pelem->ctr = elem;
    head->next = pelem;
    return true;
}

// 删除某个位置元素
bool deleteElement(singleLink *head, int n){
  if(n<0)
    return false;
  int i = 0;
  while(i<n && head){
    i++;
    head = head->next;
  }
  // delete head->next; // 释放指针内存空间
  head->next = head->next->next;
  return true;
}

// 翻转链表
singleLink* reverseLink(singleLink *head, singleLink *reveseNode){
  if(head == NULL)
      return head;
  if(head->ctr == NULL)
      head = head->next;
  auto tmp = head->next;
  head->next = reveseNode;
  if(tmp){
    return reverseLink(tmp,head);
  }else{
    return head;
  }
}
// 检测回文字符串
bool verifyPalindrome(singleLink *head,singleLink *mid){
    bool isPalindrome = false;
    if(head->ctr == NULL){
      head = head->next;
    }
    while(mid){
      if(mid->ctr != NULL){
        if(mid->ctr == head->ctr){
          isPalindrome = true;
        }else{
          isPalindrome = false;
          break;
        }
        head = head->next;
      }
      mid = mid->next;
    }
  return isPalindrome;
}
// 快慢指针获取中间节点
singleLink* midleNode(singleLink *head){
  singleLink *ps; // 这里的声明在栈中，会在出了局部作用域自动销毁
  singleLink *pf;
  if(head->ctr == NULL){
    head = head->next;
  }
  ps = pf = head;
  while(pf->next){
    if(pf->next->next){
        ps = ps->next;
        pf = pf->next->next;
    }else{
      break;
    }
  }
  if(pf->next){
    return ps->next;
  }else{
    return ps;
  }
    // delete ps;
    // delete pf;
}

int main(){
  singleLink *head = new singleLink();
  head = initSingleLink();
  head = insertRail(head,"abcdedcba");
  singleLink *mid = new singleLink();
  mid = midleNode(head);

  //if(insertElement(head,4,'D')){
  singleLink *reveseNode = new singleLink();
  reveseNode = reverseLink(mid,reveseNode);
  if(verifyPalindrome(head,reveseNode)){
    cout << "yes,is palindrome" << endl;
  }else{
    cout << "nope, it is not" << endl;
  }
  // while(reveseNode){
  //   if(reveseNode->ctr!=NULL){

  //   }
  //   head = head->next;
  //   reveseNode = reveseNode->next;
  // }
  // while(head){
  //   cout << head->ctr << endl;
  //   head = head->next;
  // }
  // }
  return 0;
}
