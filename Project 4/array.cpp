#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);

int main() {
    
    // test appendToAll
    string people[5] = { "clark", "peter", "diana", "tony", "selina" };
    assert(appendToAll(people, 5, "!!!") == 5);
    assert(people[0] == "clark!!!" && people[1] == "peter!!!" && people[2] == "diana!!!" && people[3] == "tony!!!" && people[4] == "selina!!!");
    
    // test lookup
    string people2[5] = { "clark", "peter", "diana", "tony", "selina" };
    assert(lookup(people2, 4, "peter") == 1);
    assert(lookup(people2, 4, "logan") == -1);
    
    // test positionOfMax
    string hero[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
    assert(positionOfMax(hero, 6) == 3);
    
    // test rotateLeft
    string super[5] = { "logan", "clark", "peter", "sue", "reed" };
    assert(rotateLeft(super, 5, 1) == 1);
    assert(super[0] == "logan" && super[1] == "peter" && super[2] == "sue" && super[3] == "reed" && super[4] == "clark");
    
    // test countRuns
    string d[9] = { "tony", "bruce", "steve", "steve", "diana", "diana", "diana", "steve", "steve" };
    assert(countRuns(d, 9) == 5);
    
    // test flip
    string folks[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
    assert(flip(folks, 4) == 4);
    assert(folks[0] == "tony" && folks[1] == "" && folks[2] == "steve" && folks[3] == "bruce" && folks[4] == "sue" && folks[5] == "clark");
    
    // test differ
    string folks1[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
    string group[5] = { "bruce", "steve", "clark", "", "tony" };
    assert(differ(folks1, 6, group, 5) == 2);
    assert(differ(folks1, 2, group, 1) == 1);
    string alph1[5] = { "apple", "banana", "cat", "dog", "ear" };
    string alph2[5] = { "apple", "banana", "cat", "dog", "ear" };
    assert(differ(alph1, 3, alph2, 5) == 3);
    
    // test subsequence
    string names[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
    string names1[10] = { "reed", "sue", "selina" };
    assert(subsequence(names, 6, names1, 3) == 1);
    string names2[10] = { "logan", "selina" };
    assert(subsequence(names, 5, names2, 2) == -1);
    
    // test lookupAny
    string names3[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" }; string set1[10] = { "clark", "bruce", "selina", "reed" };
    assert(lookupAny(names3, 6, set1, 4) == 1);
    string set2[10] = { "tony", "diana" };
    assert(lookupAny(names3, 6, set2, 2) == -1);
    
    // test split
    string hero1[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
    assert(split(hero1, 6, "logan") == 3);
    string hero2[4] = { "reed", "sue", "peter", "steve" };
    assert(split(hero2, 4, "steve") == 2);
    
    // extra test cases
    string h1[7] = { "selina", "reed", "diana", "tony", "", "logan", "peter" };
    assert(lookup(h1, 7, "logan") == 5);
    assert(lookup(h1, 7, "diana") == 2);
    assert(lookup(h1, 2, "diana") == -1);
    assert(positionOfMax(h1, 7) == 3);
    
    string g1[4] = { "selina", "reed", "peter", "sue" };
    assert(differ(h1, 4, g1, 4) == 2);
    assert(appendToAll(g1, 4, "?") == 4 && g1[0] == "selina?" && g1[3] == "sue?");
    assert(rotateLeft(g1, 4, 1) == 1 && g1[1] == "peter?" && g1[3] == "reed?");
    
    string e1[4] = { "diana", "tony", "", "logan" };
    assert(subsequence(h1, 7, e1, 4) == 2);
    
    string d1[5] = { "reed", "reed", "reed", "tony", "tony" };
    assert(countRuns(d1, 5) == 2);
    
    string f1[3] = { "peter", "diana", "steve" };
    assert(lookupAny(h1, 7, f1, 3) == 2);
    assert(flip(f1, 3) == 3 && f1[0] == "steve" && f1[2] == "peter");
    assert(split(h1, 7, "peter") == 3);
    
    cerr << "passed!" << endl;
}


int appendToAll(string a[], int n, string value){
    if (n < 0)
        return -1;
    for (int i = 0; i < n; i++) {   // traverse through all elements of array
        a[i] += value;              // add value to the end of each element
    }
    return n;
}


int lookup(const string a[], int n, string target){
    if (n < 0)
        return -1;
    for (int i = 0; i < n; i++){       // traverse through elements of array
        if(a[i] == target)          // if element is the target, return the index
            return i;
    }
    return -1;
}


int positionOfMax(const string a[], int n){
    if (n < 0)
        return -1;
    string max = "";
    int pos = 0;
    for (int i = 0; i < n; i++){    // traverse
        if (a[i] > max) {       // if element is greater than the current max, set max to that element
            max = a[i];
            pos = i;
        }
    }
    return pos;
}


int rotateLeft(string a[], int n, int pos){
    if (n < 0 || pos < 0 || pos >= n)
        return -1;
    string save = a[pos];
    for (int i = pos; i < n - 1; i++){      // starting from pos, shift all elements to the left
        a[i] = a[i + 1];
    }
    a[n - 1] = save;    // set last element to pos
    return pos;
}


int countRuns(const string a[], int n){
    if (n < 0)
        return -1;
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        if (a[i] != a[i + 1]){      // if element is not equal to the next element, increase count
            count++;
        }
    }
    return count + 1;
}


int flip(string a[], int n){
    if (n < 0)
        return -1;
    for (int i = 0; i < n/2; i++){      // traverse halfway
        string temp = a[i];
        a[i] = a[n-1-i];        // switch first and last element
        a[n-1-i] = temp;
    }
    return n;
}


int differ(const string a1[], int n1, const string a2[], int n2){
    if (n1 < 0 || n2 < 0)
        return -1;
    if (n1 == 0 || n2 == 0)
        return 0;
    
    if (n1 <= n2) {
        for(int i = 0; i < n1; i++){
            if (a1[i] != a2[i])         // find the differing element
                return i;
        }
    }
    else if (n2 < n1)
        for(int i = 0; i < n2; i++){
            if (a1[i] != a2[i])
                return i;
    }
    
    if (n1 < n2)
        return n1;
    return n2;
}


int subsequence(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0)
        return -1;
    if (n2 == 0)
        return 0;
    
    for (int i = 0; i < n1; i++) {
        if (a1[i] == a2[0]) {                   // find where the elements are the same
            for (int j = 0; j < n2; j++) {
                if (a1[i+j] != a2[j])       // check that the remaining elements are equal
                    return -1;
            }
            return i;
        }
    }
    return -1;
}


int lookupAny(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0)
        return -1;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {      // find if element of a1 is in a2
            if (a1[i] == a2[j])
                return i;
        }
    }
    return -1;
}

int split(string a[], int n, string splitter){
    int conc;
    if (n < 0) {
        return -1;
    }
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > splitter) {          // checks if element is larger than splitter and then stores it
            string store = a[i];
            for (int j = i; j < n - 1; j++){
                a[j] = a[j+1];      // shifts element
            }
            a[n - 1] = store;
            i--;
            counter++;
            if (counter == n) {
                if (a[i -1] > a[i]) {
                    string lastCaseShift = a[i];        // stores current element if it's smaller than previous
                    a[i] = a[i - 1];
                    a[i - 1] = lastCaseShift;
                }
                conc = i + 1;
                if(a[i] == splitter && a[i - 1] != splitter ) {     // if element is the splitter, return its index
                    conc = i;
                }
                if (a[0] > splitter) {
                    conc = n;
                }
                return conc;
            }
        }
    }
    return n;
}
