#include<iostream>
#include<vector>
#include<cmath>
#include <stdexcept>
using namespace std;


class SolveLinearSystems {
private:
    vector<vector<double> > A;
    vector<vector<double> > Abk;
    vector<double> X;
    vector<double> X0;
    double TOL = 0.001;
    int MAX_ITERATIONS = 10000;
    int dim;
    class InvalidInput: public runtime_error {
    public:
        InvalidInput(): runtime_error("Invalid input!") {}
    };
public:
    SolveLinearSystems(int num=4): dim(num) {}
    vector<vector<double> > get_Ab() const {return A;}
    vector<double> get_X() const {return X;}
    vector<double> get_X0() const {return X0;}
    double get_TOL() const {return TOL;}
    int get_dim() const {return dim;}
    int get_max_iterations() const {return MAX_ITERATIONS;}

    void set_dim() {
        cout << "\nInput the number of equations and unknowns n: ";
        cin >> dim;
        if(cin.fail()) {
            throw InvalidInput(); 
        }
        A.resize(dim);
        X.resize(dim);
        X0.resize(dim);
    }

    void set_Ab() {
        cout << "\nInput the augmented matrix of Ax=b as [A b]: " << endl;
        double a;
        for(int i=0; i<dim; i++) {
            vector<double> row(dim+1);
            for(int j=0; j<dim+1; j++) {
                cin >> a;
                if(cin.fail()) {
                    throw InvalidInput();
                }
                row[j] = a;
            }
            A[i] = row;
        }
        Abk = A;
    }

    void set_X0() {
        double a;
        cout << "\nInput the initial approximation x(0): " << endl;
        for(int i=0; i<dim; i++) {
            cin >> a;
            if(cin.fail()) {
                throw InvalidInput();
            }
            X0[i] = a;
        }
    }

    int judge() {
        for(int i=0; i<Abk.size()-1; i++) {
            int nz = -1;
            for(int p=i; p<Abk.size(); p++) {
                if(Abk[p][i] != 0) {
                    nz = p;
                    break;
                }
            }
            if(nz == -1) {
                cout << "\nNo unique solution exists!" << endl;
                return 1;
            }
            if(nz != i) {
                Abk[nz].swap(Abk[i]);
            }
            // elimination process
            for(int j=i+1; j<Abk.size(); j++) {
                double temp = Abk[j][i] / Abk[i][i];
                for(int k=i; k<Abk.size()+1; k++) {
                    Abk[j][k] -= temp * Abk[i][k];
                }
            }
        }
        if(Abk[dim-1][dim-1] == 0) {
            cout << "\nNo unique solution exists!" << endl;
            return 1;
        }
        return 0;
    }

    void GaussianElimination() {
        // row from 0 to n-2
        for(int i=0; i<A.size()-1; i++) {
            int nz = -1;
            for(int p=i; p<A.size(); p++) {
                if(A[p][i] != 0) {
                    nz = p;
                    break;
                }
            }
            if(nz != i) {
                A[nz].swap(A[i]);
            }
            // elimination process
            for(int j=i+1; j<A.size(); j++) {
                double temp = A[j][i] / A[i][i];
                for(int k=i; k<A.size()+1; k++) {
                    A[j][k] -= temp * A[i][k];
                }
            }
        }
        X[dim-1] = A[dim-1][dim] / A[dim-1][dim-1];
        for(int i=dim-2; i>=0; i--) {
            double sum = 0;
            for(int j=i+1; j<dim; j++) {
                sum += A[i][j] * X[j];
            }
            X[i] = (A[i][dim] - sum) / A[i][i];
        }
    }

    void JacobiIterative() {
        set_X0();
        int k = 0;
        while(k < MAX_ITERATIONS) {
            for(int i=0; i<dim; i++) {
                double sum = 0;
                for(int j=0; j<dim; j++) {
                    if(j == i) continue;
                    sum += A[i][j] * X0[j];
                }
                X[i] = 1 / A[i][i] * (A[i][dim] - sum);
            }
            double error = 0, max_item = 0;
            for(int i=0; i<dim; i++) {
                error = X[i]-X0[i];
                if(error < 0) error = -error;
                if(error > max_item) max_item = error;
            }
            if(max_item < TOL) {
                return;
            }
            X0 = X;
            k++;
        }
        cout << "\nMaximum number of iterations exceeded!" << endl;
    }

    void solve() {
        int method = 1;
        cout << "\n[0] Jacobi Iteration  [1] Gaussian Elimination" << endl;
        cout << "Choose a method: ";
        cin >> method;
        if(method != 0 && method != 1) {
            throw InvalidInput();
        }
        if(method)
            GaussianElimination();
        else
            JacobiIterative();
    }
};


int main() {
    SolveLinearSystems obj;
    try
    {
        obj.set_dim();
        obj.set_Ab();
        if(obj.judge()) return 0;
        else obj.solve();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }

    vector<double> res = obj.get_X();
    cout << "\nResults is: " << endl;
    for(auto x: res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
