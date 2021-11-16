#include <iostream>
#include <Eigen\Dense>
#include <cmath>

using namespace std;

int polynomial_size = 2; //n차 방정식을 나타냄 ex)3차 방정식 : 3

int main()
{
    int count; //x,y Pair의 갯수
    cout << "x,y의 Pair의 수를 입력해 주세요 : " << endl;
    cin >> count;

    double* x = new double[count];
    double* y = new double[count];
    double Sr=0;
    double St=0;
    double Syx=0;
    double r_2=0;
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << "번째 x의 수를 입력해 주세요 " << endl;
        cin >> x[i];
        cout << i + 1 << "번째 y의 수를 입력해 주세요 " << endl;
        cin >> y[i];
    }
    
    Eigen::MatrixXd A(count, polynomial_size+1);
    Eigen::MatrixXd X;
    Eigen::MatrixXd Y(count, 1);

    //A의 값과 Y의 값을 넣어준다
    for (int i = 0; i < A.rows(); i++)
    {
        for (int j = 0; j < A.cols(); j++)
        {
            A(i, j) = pow(x[i], j);
        }
    }
    for (int i = 0; i < A.rows(); i++)
    {
        Y(i, 0) = y[i];
    }

    //a0,a1....an까지를 구한다 
    Eigen::MatrixXd t1 = A.transpose() * A;
    t1 = t1.inverse();
    X = t1 * A.transpose() * Y;


    //Sr을 구한다  -- 
    for (int i = 0; i < count; i++)
    {
        double temp = 0;
        for (int j = 0; j < X.rows(); j++)
        {
            temp += X(j, 0) * pow(x[i], j);
        }
        Sr += pow(Y(i, 0) - temp, 2);
    }

    //St를 구한다
    double y_average = 0;
    //평균을 구함
    for (int i = 0; i < count; i++)
    {
        y_average += y[i];
    }
    y_average = y_average / count;
    
    for (int i = 0; i < count; i++)
    {
        St += pow(Y(i, 0) - y_average, 2);
    }

    //Syx를 구한다
    Syx = sqrt(Sr / count - (polynomial_size + 1));

    //r^2를 구한다
    r_2 = 1 - (Sr / St);

    cout << "Coefficients : " <<"\n" << X <<"\n ---------------------------------------------------" << endl;  
    cout << "Sr : " << Sr << "\n ---------------------------------------------------" << endl;
    cout << "St : " << St << "\n ---------------------------------------------------" << endl;
    cout << "Syx : " << Syx << "\n ---------------------------------------------------" << endl;
    cout << "r^2 : " << r_2 << "\n ---------------------------------------------------" << endl;

}

