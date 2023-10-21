/**
 * @file main.cpp
 * @author Austin Smith aust4513@vandals.uidaho.edu
 * @brief 
 * @version 0.1
 * @date 2023-09-08
 * 
 */

#include <iostream>
using namespace std;
#include "functions.h"
#include "matplotlibcpp.h"

int main()
{
    //Generates random seed
    start:
    cout << "\033[2J\033[1;1H";
    srand((unsigned) time(NULL));
    int N;
    int xgridsize;
    int ygridsize;
    char random;
    ofstream file("Solution.txt");
    sleep(5);
    file.clear();



    //begins code
    std::cout<<"\nPlease enter the number of points you would like to check: ";
    cin>> N;
    long long unsigned int tempo = (long long unsigned) N;
    long long unsigned int fact = factorial(tempo);
    //cout<<factorial(tempo)<<"\n"<<fact<<endl;
    vector<int> xpoints(N);
    vector<int> ypoints(N);
    std::cout<<"\nWould you like to Manually enter points, use a Uniform random distribution, or use a Noisy line? (M, U, or N) ";
    cin>>random;
    if (random == 'M' || random == 'm'){
        for (int i=0; i < N; i++){
            int xtemp = 0;
            int ytemp = 0;
            std::cout<<"\nEnter the "<< i+1 << article(i) <<" x-value: ";
            cin>>xtemp;
            std::cout<<"\nEnter the "<< i+1 << article(i) <<" y-value: ";
            cin>>ytemp;
            xpoints[i] = xtemp;
            ypoints[i] = ytemp;
        }
        int xmax = *max_element(xpoints.begin(), xpoints.end());
        int ymax = *max_element(ypoints.begin(), ypoints.end());
        xgridsize = xmax;
        ygridsize = ymax;
    }
    else if (random == 'N' || random == 'n'){
        xgridsize = N;
        retry:
        int rslope = 1;//generaterandom(N/20);
        if (rslope == 0){
            ygridsize = N;
        }
        else{
            ygridsize = rslope * N;
        }
        int rintercept = generaterandom(N/20);
        for (int i=0; i < N; i++){
            int temp = rand() % (2*xgridsize + 1) - xgridsize;
            xpoints[i] = temp;
        }
        for (int i=0; i < N; i++){
            int temp = xpoints[i]*rslope + rintercept + generaterandom(N/10);
            if (temp > ygridsize){
                temp = ygridsize;
            }
            if (temp < -ygridsize){
                temp = -ygridsize;
            }
            for (int j = 0; j < i; j++){
                int loopcount = 0;
                while (xpoints[j] == xpoints[i] && ypoints[j] == temp){
                    if (loopcount > N){
                        //cout<<"retrying"<<endl;
                        goto retry;
                    }
                    temp = xpoints[i]*rslope + rintercept + generaterandom(N/10);
                    if (temp > ygridsize){
                        temp = ygridsize;
                    }
                    if (temp < -ygridsize){
                        temp = -ygridsize;
                    }
                    loopcount++;
                }
            }
            ypoints[i] = temp;
        }     
    }
    else{
        xgridsize = (int)(N/4);
        ygridsize = (int)(N/4);
        for (int i=0; i < N; i++){
            int temp = rand() % (2*xgridsize + 1) - xgridsize;
            xpoints[i] = temp;
        }


        for (int i=0; i < N; i++){
            int temp = rand() % (2*ygridsize + 1) - ygridsize;
            for (int j = 0; j < i; j++){
                while (xpoints[j] == xpoints[i] && ypoints[j] == temp){
                    temp = rand() % (2*ygridsize + 1) - ygridsize;
                }
            }
            ypoints[i] = temp;
        }        
    }
    //Prints all points
    //printvector(xpoints, ypoints);
    for (int j=0; j < xpoints.size(); j++){
        file <<"("<<xpoints[j]<<", "<<ypoints[j]<<"), ";
    }
    file<<"\n\n"<<endl;
    matplotlibcpp::figure_size(1200,1200);
    matplotlibcpp::xlim(-xgridsize, xgridsize);
    matplotlibcpp::ylim(-ygridsize, ygridsize);
    matplotlibcpp::grid(true);
    matplotlibcpp::plot(xpoints, ypoints, "ro");
    matplotlibcpp::title("Visualizing the generated points", {{"fontsize", "20"}});
    clock_t t1, t2, t3, t4, t5;
    t1 = clock();
    t2 = clock();
    t3 = clock();
    t4 = clock(); 
    t5 = clock(); 
    //initializes combinations
    vector<Combination> nCr;
    for (long long unsigned int i=0; i < fact; i++){
        nCr.push_back(Combination());
    }
    // Generates all combinations
    generatecombo(nCr, xpoints, ypoints, fact, N);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    file<<"Generating combinations took "<<time_taken1<<" seconds"<<endl;
    /*for (int i = 0; i < nCr.size(); i++){
        for (int j=0; j < nCr[i].xcoords.size(); j++){
            file <<"("<<nCr[i].xcoords[j]<<", "<<nCr[i].ycoords[j]<<"), ";
        }
        file <<"\n";  
    }*/


    //Case if all points have det != 0
    if (nCr.size() == 0){
        file<<"No 3 points are collinear"<<endl;
        t5 = clock() - t5;
        double time_taken5 = ((double)t5)/CLOCKS_PER_SEC;
        file<<"This total program took "<<time_taken5<<" seconds"<<endl;
        file.close();
        matplotlibcpp::show();
        matplotlibcpp::close();
        cout << "\033[2J\033[1;1H";
        goto start;
        return(0);
    }

    //Calculates slopes and intercepts
    for (int i=0; i < nCr.size(); i++){
        nCr[i].slope = slopecalc(nCr[i].xcoords, nCr[i].ycoords, N);
        nCr[i].intercept = interceptcalc(nCr[i].xcoords, nCr[i].ycoords, nCr[i].slope, N);
    }
    t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
    file<<"Finding the slopes and int. took "<<time_taken2 - time_taken1<<" seconds"<<endl;
    //Combines all combinations into only those with unique slope and intercept
    combine(nCr);
    t3 = clock() - t3;
    double time_taken3 = ((double)t3)/CLOCKS_PER_SEC;
    file<<"Combining took "<<time_taken3 - time_taken2<<" seconds"<<endl;
    //Evaluates sizes
    int largest = 0;
    
    for (int i=0; i < nCr.size(); i++){
        if(nCr[i].xcoords.size() > largest){
            largest = nCr[i].xcoords.size();
        }
    }
    t4 = clock() - t4;
    double time_taken4 = ((double)t4)/CLOCKS_PER_SEC;
    file<<"Finding the largest took "<<time_taken4 - time_taken3<<" seconds"<<endl;
    //Largest size
    file<<"\nThe largest number of collinear points is " << largest <<endl;
    std::ostringstream oss;
    oss << "The largest number of collinear points is " << largest;
    std::string sup = oss.str();
    matplotlibcpp::suptitle(sup, {{"fontsize", "35"}});

    int iterator = 0; //used for the article (1st, 2nd, 3rd)
    for (int i = 0; i < nCr.size(); i++){

        //only check those with the largest number of points
        if (nCr[i].xcoords.size() == largest){

            //check for undefined case
            if (nCr[i].slope == 3 * N){
                matplotlibcpp::axvline(nCr[i].xcoords[0], -ygridsize, ygridsize, {{"color", "b"}});
                file<<"\nThe "<< iterator + 1 << article(iterator) <<" equation is x = "<<nCr[i].xcoords[0]<<endl;
                file<<"It contains the points: ";
                for (int j=0; j < nCr[i].xcoords.size(); j++){
                    file <<"("<<nCr[i].xcoords[j]<<", "<<nCr[i].ycoords[j]<<"), ";
                }
                file <<"\n";
                matplotlibcpp::plot(nCr[i].xcoords, nCr[i].ycoords, "ko");  
            } else if (nCr[i].slope == 0){
                matplotlibcpp::axhline(nCr[i].ycoords[0], -xgridsize, xgridsize, {{"color", "b"}});
                file<<"\nThe "<< iterator + 1 << article(iterator) <<" equation is y = "<<nCr[i].ycoords[0]<<endl;
                file<<"It contains the points: ";
                for (int j=0; j < nCr[i].xcoords.size(); j++){
                    file <<"("<<nCr[i].xcoords[j]<<", "<<nCr[i].ycoords[j]<<"), ";
                } 
                matplotlibcpp::plot(nCr[i].xcoords, nCr[i].ycoords, "ko");  
            } else{
                vector<int> ytemp = {-ygridsize, ygridsize};
                vector<double> xtemp = {(-(double)ygridsize - nCr[i].intercept)/nCr[i].slope, ((double)ygridsize - nCr[i].intercept)/nCr[i].slope};
                matplotlibcpp::plot(xtemp,ytemp,"b-");
                file<<"\nThe "<< iterator + 1 << article(iterator) <<" equation has slope "<< nCr[i].slope<<" and intercept "<< nCr[i].intercept<<endl;
                file<<"It contains the points: ";
                for (int j=0; j < nCr[i].xcoords.size(); j++){
                    file <<"("<<nCr[i].xcoords[j]<<", "<<nCr[i].ycoords[j]<<"), ";
                }
                matplotlibcpp::plot(nCr[i].xcoords, nCr[i].ycoords, "ko");
            }
            iterator++;
        }
    }
    t5 = clock() - t5;
    double time_taken5 = ((double)t5)/CLOCKS_PER_SEC;
    file<<"\nThis total program took "<<time_taken5<<" seconds"<<endl;
    file.close();
    matplotlibcpp::show();
    matplotlibcpp::close();
    cout << "\033[2J\033[1;1H";
    goto start;
    return(0);
}