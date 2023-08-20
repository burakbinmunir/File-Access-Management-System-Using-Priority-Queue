#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class User
{
	template<class T> friend class FileList;

	friend ostream& operator<<(ostream& write, User& object) {
		write << endl << endl;

		write << "Priority Key: " << object.key << " ID: " << object.userID << " Operation: " << object.operationType;

		if (object.grantaccess == true)
			write << "Access Granted\n";
		else write << "Access Denied";

		write << endl << endl;
		return write;
	}
public:
	// Defualt Constructor
	User() {
		key = NULL;
		userID = NULL;
		operationType = "";
		grantaccess = false;
	}

	// Overloaded Constructor
	User(int key, int userID, string operationType) {
		this->key = key;
		this->userID = userID;
		this->operationType = operationType;
		this->grantaccess = false;
	}

	

	// Prints' user's information
	void PrintUser() {
		cout << endl << endl;

		cout << "Key: "<<key << " ID: " << userID << " Operation: " << operationType;

		if (grantaccess == true)
			cout << "Access given";
		else cout << "Access denied";

		cout << endl << endl;
	}
															
	template<class T> friend class PriorityQueue;
private:
	int key;	 // priority key
	int userID;	
	string operationType;	// read or write
	bool grantaccess;
};

template<class T>
class PriorityQueue		// Max Heap
{
	friend ostream& operator<<(ostream& write, PriorityQueue& object) {
		write << "Printing Queue\n";
		for (int index = NULL; index < object.currentSize; index++) {
			//if (object.queue[index].)
			write << object.queue[index];
		}
		return write;
	}
public:
	// Default Constructor
	PriorityQueue() {
		capacity = 100;
		queue.resize(capacity);
		currentSize = NULL;
	}

	//Overloaded Constructor
	PriorityQueue(int capacity) {
		if (capacity > NULL) {
			this->capacity = capacity;
		}
		else this->capacity = 100;
		queue.resize(capacity);
		currentSize = NULL;
	}

	// Add new user to waiting queue
	void AddToQueue(T newElement) {
		queue[currentSize] = newElement;
		ReHeapUp(currentSize);
		currentSize++;
	}

	//PriorityQueue<T> BuildQueue(vector<T> unsortedQueue) {
	//	PriorityQueue<T> newQueue(unsortedQueue.size());
	//	for (int index = NULL; index < unsortedQueue.size(); index++)
	//		newQueue.AddToQueue(unsortedQueue[index]);
	//	return newQueue;
	//	/*for (int index = unsortedQueue.size()/2- 1; index >= NULL; index--)
	//	{
	//		Heapify(index, unsortedQueue);
	//	}
	//	for (int index = unsortedQueue.size() - 1; index >= NULL; index--) {
	//		swap(unsortedQueue[0], unsortedQueue[index]);
	//		Heapify(index, unsortedQueue);
	//	}
	//	return unsortedQueue;*/
	//}

	// Extract Max 
	T ExtractMax() {
		T currentMax = queue[NULL];
		DeleteMax();
		return currentMax;
	}

	// returns user with maximum priority
	T FindMax() {
		return queue[NULL];
	}

	// returns user with low priority
	T FindMin() {
		return queue[currentSize - 1];
	}

	// returns true if queue if empty
	bool IsEmpty() {
		return (currentSize == NULL);
	}

	// Returns current Size;
	int Size() {
		return currentSize;
	}

	

	
	//// Prints Queue
	//void ShowQueue() {
	//	cout << "Printing Queue";
	//	for (int index = NULL; index < currentSize; queue[index].PrintUser(), index++);
	//}

	// Default Destructor
	~PriorityQueue() {
		queue.resize(NULL);
		capacity = NULL;
		currentSize = NULL;
	}

private:
	vector<T> queue;
	int currentSize;	// current number of users in queue
	int capacity;	// total capacity of queue to hold users

	/****************** M E T H O D S ************************/

	// Returns the index of parent node
	int ParentUser(int currentUser) {
		return ((currentUser - 1) / 2);
	}

	// Returns the index of left child
	int LeftUser(int currentUser) {
		return (2 * currentUser + 1);
	}

	// Returns the index of right child node
	int RightUser(int currentUser) {
		return (2 * currentUser + 2);
	}

	// Helping functions to maintain the priority of heap
	void ReHeapUp(int currentIndex) {
		if (currentIndex == NULL)
			return;
		else
		{
			int parentUser = ParentUser(currentIndex);
			if (queue[parentUser].key < queue[currentIndex].key)
				swap(queue[parentUser] ,queue[currentIndex]);

			ReHeapUp(currentIndex - 1);
		}
	}

	// Helping functions to maintain the priority of heap
	void ReHeapDown(int currentIndex) {
		if (currentIndex == currentSize)
			return;
		else
		{
			int leftuser = LeftUser(currentIndex);	// leftchild
			int rightuser = RightUser(currentIndex);
			if (leftuser < currentSize && queue[currentIndex].key < queue[leftuser].key)
				swap(queue[currentIndex], queue[leftuser]);

			if (rightuser < currentSize && queue[currentIndex].key < queue[rightuser].key)
				swap(queue[currentIndex], queue[rightuser]);

			ReHeapDown(currentIndex + 1);
		}
	}

	void Heapify(int index, vector<T>& unsortedQueue) {
		int currentindex = index;
		int right = RightUser(index);
		int left = LeftUser(index);
		if (left < unsortedQueue.size() && unsortedQueue[left] > unsortedQueue[currentindex])
			currentindex = left;
		if (right < unsortedQueue.size() && unsortedQueue[right] > unsortedQueue[currentindex])
			currentindex = right;
		if (currentindex != index) {
			swap(unsortedQueue[index], unsortedQueue[currentindex]);
			Heapify(currentindex, unsortedQueue);
		}
	}

	// Deletes the user with maximum priority
	void DeleteMax() {
		queue[NULL] = queue[currentSize - 1];
		currentSize--;
		ReHeapDown(NULL);
	}
};

template<class T>
class File
{
	template<class T> friend class FileList;

	template<class T> friend class HashTable;

	friend ostream& operator<<(ostream& write, File<T>& object) {
		write << endl << endl;

		write << "FileName: " << object.filename << " File ID: " << object.fileID;
		write << endl;
		write << object.accessors;
		write << endl << endl;
		return write;
	}
public:
	File() {
		filename = "";
		fileID = -1;
		accessors = nullptr;
		numberOfAccessors = NULL;
	}

	File(string filename, int fileID) {
		this->fileID = fileID;
		this->filename = filename;
		this->numberOfAccessors = NULL;
	}

	bool IsEmpty() {
		return (filename == "" && fileID == -1 && accessors == nullptr && numberOfAccessors == NULL);
	}
	//~File();

private:
	string filename;
	int fileID;
	int numberOfAccessors;
	PriorityQueue<User<T>> accessors;
};

template<class T>
class FileList
{
public:
	list<File<T>> files;
	int numberoffiles;

	void PrintFileList() {
		for (auto& ele : files)
			cout << ele;
	}

	void GrantAccess(User<T> newUser, int fileID) {
		bool placed = false;

		for (auto& ele : files) {
			if (ele.fileID == fileID) {
				if (ele.numberOfAccessors == NULL) {
					newUser.grantaccess = true;
					placed = true;
					ele.numberOfAccessors++;
					break;
				}
				else {
					ele.accessors.AddToQueue(newUser);
					placed = true;
				}
			}			
		}

		if (placed == false)
			cout << "File not found\n";
	}

	void AddFile(File<T> newFile) {
		files.push_front(newFile);
		numberoffiles++;
	}

	bool IsEmpty() {
		return (files.size() == NULL);
	}
};

template<class T>
class HashTable
{
public:
	//	Defualt Constructor
	HashTable() {
		tableSize = 11;
		hash.resize(tableSize);
		currentFiles = NULL;
	}

	// Overloaded Constructor
	HashTable(int tableSize) {
		this->tableSize = tableSize;
		hash.resize(tableSize);
		currentFiles = NULL;
	}

	// Inserts file in hashtable
	void InsertFile(File<T> newFile) {
		int id = newFile.fileID;
		int hashIndex = id % tableSize;
		hash[hashIndex].AddFile(newFile);
		currentFiles++;
	}

	// Prints the hash table
	void PrintHash() {
		
		for (int index = NULL; index < tableSize; index++)
			if (!hash[index].IsEmpty())
				hash[index].PrintFileList();
	}
		
	void RequestFileAcces(int userID,int priority, int fileID,string operationType) {
		int hashIndex = fileID % tableSize;
		if (hash[hashIndex].IsEmpty()) {
			cout << "No Such File exists\n";
			return;
		}
		else
		{
			User<T> newUser(priority, userID, operationType);
			hash[hashIndex].GrantAccess(newUser,fileID);
		}
					
	}

	//~HashTable();

private:
	int tableSize;
	vector<FileList<T>> hash;
	int currentFiles;

};
//int main() {
//	/*User<int> user1(3, 3, "Read");
//	User<int> user2(1, 1, "Write");
//	User<int> user3(2, 2, "Read");*/
//	/*User<int> user6(0, 2, "Read");
//	User<int> user4(4, 2, "Read");
//	User<int> user5(5, 2, "Read");*/
//	//
//	//PriorityQueue<User<int>> myQueue;
//	//myQueue.AddToQueue(user1);
//	//myQueue.AddToQueue(user2);
//	//myQueue.AddToQueue(user3);
//	/*myQueue.AddToQueue(user4);
//	myQueue.AddToQueue(user5);
//	myQueue.AddToQueue(user6);*/
//	User u1(20, 1, "r");
//	User u2(1, 2, "r");
//	User u3(40, 3, "r");
//	User u4(0, 4, "r");
//	User u5(5, 5, "r");
//	User u6(9, 6, "r");
//	User u7(110, 7, "r");
//	
//	PriorityQueue<User> q;
//	q.AddToQueue(u1);
//	q.AddToQueue(u2);
//	q.AddToQueue(u3);
//	q.AddToQueue(u4);
//	q.AddToQueue(u5);
//	q.AddToQueue(u6);
//	q.AddToQueue(u7);
//	
//	cout << q;
//	 q.FindMin().PrintUser();
//
//	//myQueue.ExtractMax().PrintUser();
//
//	//File<int> newfile1("file01", 01);
//	//File<int> newfile2("file02", 12);
//	//File<int> newfile3("file03", 03);
//	//
//	//HashTable<int>	  table;
//	//table.InsertFile(newfile1);
//	//table.InsertFile(newfile2);
//	//table.InsertFile(newfile3);
//	////table.PrintHash();
//
//	//int userID = 01;
//	//int priority = 1;
//	//int fileID = 1;
//	//string operationType = "write";
//
//	//table.RequestFileAcces(userID, priority, fileID, operationType);
//	//table.RequestFileAcces(2, priority, 12, operationType);
//	//table.RequestFileAcces(2, priority, 12, operationType);
//
//	//table.PrintHash();
//	/*myQueue.FindMax().PrintUser();
//	myQueue.FindMin().PrintUser();*/
//
//
//	//myQueue.ShowQueue();
//	
//	
//
//
//}