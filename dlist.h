#ifndef __DLIST_H__
#define __DLIST_H__


/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
  // OVERVIEW: an exception class

};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:
  // Operational methods

  template<typename T>
  bool Dlist<T>::IsEmpty() const {
  // EFFECTS: returns true if list is empty, false otherwise
    return (first == NULL && last == NULL);
  }

  template<typename T>
  void Dlist<T>::InsertFront(const T &o) {
  // MODIFIES this
  // EFFECTS inserts o at the front of the list
    if(first==NULL && last==NULL) {
      first = new Node;
      first -> o = O;
      first -> next = first -> prev = NULL;
      last = first;
      return;
    }
    else {
      Node *newNode = new Node;
      newNode -> o = o;
      newNode -> prev = NULL;
      newNode -> next = first;
      first -> prev = newNode;
      first = newNode;
    }
  }

  template<typename T>  
  void Dlist<T>::InsertBack(const T &o) {
  // MODIFIES this
  // EFFECTS inserts o at the back of the list
    if(first==NULL && last==NULL) {
      first = newNode;
      first -> o = O;
      first -> next = first -> prev = NULL;
      last = first;
      return;
    }
    else {
      Node *newNode = new Node;
      newNode -> o = o;
      newNode -> next = NULL;
      newNode -> prev = last;
      last -> next = newNode;
      last = newNode;
    }
  }

  template<typename T>
  T Dlist<T>::RemoveFront() {
  // MODIFIES this
  // EFFECTS removes and returns first object from non-empty list
    if(first==NULL)
      throw "!*!*!List is Empty!*!*!"  //throws an instance of emptyList if empty
    else if (first==last) {
      RemoveAll();
      MakeEmpty();
      return;
    }
    else {
      Node *save = first;
      first = first -> next;
      first -> prev = NULL;
      save -> next = NULL;
      delete save;
    }
  }

  template<typename T>
  T Dlist<T>::RemoveBack() {
  // MODIFIES this
  // EFFECTS removes and returns last object from non-empty list
    if(last==NULL)
      throw "!*!*!List is Empty!*!*!"
  //throws an instance of emptyList if empty

    else if (first == last) {
      RemoveAll();
      MakeEmpty();
      return;
    }
    else {
      Node *save = last;
      last = last -> prev;
      last -> next = NULL;
      save -> prev = NULL;
      delete save;
   }
  }

  // Maintenance methods
  Dlist();                                   // ctor
  Dlist(const Dlist &l);                     // copy ctor
  Dlist &operator=(const Dlist &l);          // assignment
  ~Dlist();                                  // dtor

 private:
  // A private type
  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  node   *first; // The pointer to the first node (0 if none)
  node   *last;  // The pointer to the last node (0 if none)
  //How us this different than the doubly linked list in class?

  // Utility methods
  template<typename T>
  Dlist<T>::Dlist() {
    MakeEmpty();
  }
  // void MakeEmpty();
  // EFFECT: called by constructors to establish empty
  // list invariant

  template<typename T>
  void Dlist<T>::RemoveAll() {
    delete[] first;
    delete[] last;
  }  
  // void RemoveAll();
  // EFFECT: called by destructor and operator= to remove and destroy
  // all list nodes
  
  template<typename T>
  Dlist<T>::(const Dlist &l) {
    CopyAll(l);
  }
  //void CopyAll(const Dlist &l);
  // EFFECT: called by copy constructor/operator= to copy nodes
  // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/


/* this must be at the end of the file */
#endif /* __DLIST_H__ */
