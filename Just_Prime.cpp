#include <iostream>
#include <vector>

using namespace std;

class Factorizer {
public:
    vector<int> pFact(int numb) {
        vector<int> factor;

        if (numb <= 1) {
            return factor; 
        }

        
        while (numb % 2 == 0) {
            factor.push_back(2);
            numb /= 2;
        }

    
        for (int i = 3; i * i <= numb; i += 2) {
            while (numb % i == 0) {
                factor.push_back(i);
                numb /= i;
            }
        }

        
        if (numb > 2) {
            factor.push_back(numb);
        }

        return factor;
    }
};


void runTest(Factorizer& f, int ex) {
    vector<int> result = f.pFact(ex);

    cout << "primeFactors(" << ex << ") = [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Factorizer factorizer;

    runTest(factorizer, 0);   
    runTest(factorizer, 1);  
    runTest(factorizer, 9);   
    runTest(factorizer, 10);  
    runTest(factorizer, 19);
    runTest(factorizer, 24);  
    runTest(factorizer, 36);
    runTest(factorizer, 200);

    return 0;
}