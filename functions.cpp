/**
 * @file functions.cpp
 * @author Austin Smith aust4513@vandals.uidaho.edu
 * @brief 
 * @version 0.1
 * @date 2023-09-08
 * 
 */
#include "functions.h"

using namespace std;


//Pre calculates c(n, 3). So now just uses a lookup table
long long unsigned int factorial(long long unsigned int n) {
  long long unsigned arr[1000] = {1 , 4 , 10 , 20 , 35 , 56 , 84 , 120 , 165 , 220 , 286 , 364 ,
   455 , 560 , 680 , 816 , 969 , 1140 , 1330 , 1540 , 1771 , 2024 , 2300 , 2600 , 2925 , 3276 , 3654 , 4060 , 4495 , 4960 , 5456 , 5984 , 6545 , 7140 , 7770 ,
    8436 , 9139 , 9880 , 10660 , 11480 , 12341 , 13244 , 14190 , 15180 , 16215 , 17296 , 18424 , 19600 , 20825 , 22100 , 23426 , 24804 , 26235 , 27720 , 29260 , 30856 , 32509 ,
     34220 , 35990 , 37820 , 39711 , 41664 , 43680 , 45760 , 47905 , 50116 , 52394 , 54740 , 57155 , 59640 , 62196 , 64824 , 67525 , 70300 , 73150 , 76076 , 79079 , 82160 , 85320 , 88560 ,
      91881 , 95284 , 98770 , 102340 , 105995 , 109736 , 113564 , 117480 , 121485 , 125580 , 129766 , 134044 , 138415 , 142880 , 147440 , 152096 , 156849 , 161700 , 166650 , 171700 , 176851 ,
       182104 , 187460 , 192920 , 198485 , 204156 , 209934 , 215820 , 221815 , 227920 , 234136 , 240464 , 246905 , 253460 , 260130 , 266916 , 273819 , 280840 , 287980 , 295240 , 302621 , 310124 , 317750 , 325500 , 333375 ,
        341376 , 349504 , 357760 , 366145 , 374660 , 383306 , 392084 , 400995 , 410040 , 419220 , 428536 , 437989 , 447580 , 457310 , 467180 , 477191 , 487344 , 497640 , 508080 , 518665 , 529396 , 540274 , 551300 , 562475 , 573800 , 585276 , 596904 , 608685 , 620620 , 632710 , 644956 , 657359 , 669920 , 682640 , 695520 , 708561 , 721764 , 735130 , 748660 , 762355 , 776216 , 790244 , 804440 , 818805 , 833340 , 848046 , 862924 , 877975 , 893200 , 908600 , 924176 , 939929 , 955860 , 971970 , 988260 , 1004731 , 1021384 , 1038220 , 1055240 , 1072445 , 1089836 , 1107414 , 1125180 , 1143135 , 1161280 , 1179616 , 1198144 , 1216865 , 1235780 , 1254890 , 1274196 , 1293699 , 1313400 , 1333300 , 1353400 , 1373701 , 1394204 , 1414910 , 1435820 , 1456935 , 1478256 , 1499784 , 1521520 , 1543465 , 1565620 , 1587986 , 1610564 , 1633355 , 1656360 , 1679580 , 1703016 , 1726669 , 1750540 , 1774630 , 1798940 , 1823471 , 1848224 , 1873200 , 1898400 , 1923825 , 1949476 , 1975354 , 2001460 , 2027795 , 2054360 , 2081156 , 2108184 , 2135445 , 2162940 , 2190670 , 2218636 , 2246839 , 2275280 , 2303960 , 2332880 , 2362041 , 2391444 , 2421090 , 2450980 , 2481115 , 2511496 , 2542124 , 2573000 , 2604125 , 2635500 , 2667126 , 2699004 , 2731135 , 2763520 , 2796160 , 2829056 , 2862209 , 2895620 , 2929290 , 2963220 , 2997411 , 3031864 , 3066580 , 3101560 , 3136805 , 3172316 , 3208094 , 3244140 , 3280455 , 3317040 , 3353896 , 3391024 , 3428425 , 3466100 , 3504050 , 3542276 , 3580779 , 3619560 , 3658620 , 3697960 , 3737581 , 3777484 , 3817670 , 3858140 , 3898895 , 3939936 , 3981264 , 4022880 , 4064785 , 4106980 , 4149466 , 4192244 , 4235315 , 4278680 , 4322340 , 4366296 , 4410549 , 4455100 , 4499950 , 4545100 , 4590551 , 4636304 , 4682360 , 4728720 , 4775385 , 4822356 , 4869634 , 4917220 , 4965115 , 5013320 , 5061836 , 5110664 , 5159805 , 5209260 , 5259030 , 5309116 , 5359519 , 5410240 , 5461280 , 5512640 , 5564321 , 5616324 , 5668650 , 5721300 , 5774275 , 5827576 , 5881204 , 5935160 , 5989445 , 6044060 , 6099006 , 6154284 , 6209895 , 6265840 , 6322120 , 6378736 , 6435689 , 6492980 , 6550610 , 6608580 , 6666891 , 6725544 , 6784540 , 6843880 , 6903565 , 6963596 , 7023974 , 7084700 , 7145775 , 7207200 , 7268976 , 7331104 , 7393585 , 7456420 , 7519610 , 7583156 , 7647059 , 7711320 , 7775940 , 7840920 , 7906261 , 7971964 , 8038030 , 8104460 , 8171255 , 8238416 , 8305944 , 8373840 , 8442105 , 8510740 , 8579746 , 8649124 , 8718875 , 8789000 , 8859500 , 8930376 , 9001629 , 9073260 , 9145270 , 9217660 , 9290431 , 9363584 , 9437120 , 9511040 , 9585345 , 9660036 , 9735114 , 9810580 , 9886435 , 9962680 , 10039316 , 10116344 , 10193765 , 10271580 , 10349790 , 10428396 , 10507399 , 10586800 , 10666600 , 10746800 , 10827401 , 10908404 , 10989810 , 11071620 , 11153835 , 11236456 , 11319484 , 11402920 , 11486765 , 11571020 , 11655686 , 11740764 , 11826255 , 11912160 , 11998480 , 12085216 , 12172369 , 12259940 , 12347930 , 12436340 , 12525171 , 12614424 , 12704100 , 12794200 , 12884725 , 12975676 , 13067054 , 13158860 , 13251095 , 13343760 , 13436856 , 13530384 , 13624345 , 13718740 , 13813570 , 13908836 , 14004539 , 14100680 , 14197260 , 14294280 , 14391741 , 14489644 , 14587990 , 14686780 , 14786015 , 14885696 , 14985824 , 15086400 , 15187425 , 15288900 , 15390826 , 15493204 , 15596035 , 15699320 , 15803060 , 15907256 , 16011909 , 16117020 , 16222590 , 16328620 , 16435111 , 16542064 , 16649480 , 16757360 , 16865705 , 16974516 , 17083794 , 17193540 , 17303755 , 17414440 , 17525596 , 17637224 , 17749325 , 17861900 , 17974950 , 18088476 , 18202479 , 18316960 , 18431920 , 18547360 , 18663281 , 18779684 , 18896570 , 19013940 , 19131795 , 19250136 , 19368964 , 19488280 , 19608085 , 19728380 , 19849166 , 19970444 , 20092215 , 20214480 , 20337240 , 20460496 , 20584249 , 20708500 , 20833250 , 20958500 , 21084251 , 21210504 , 21337260 , 21464520 , 21592285 , 21720556 , 21849334 , 21978620 , 22108415 , 22238720 , 22369536 , 22500864 , 22632705 , 22765060 , 22897930 , 23031316 , 23165219 , 23299640 , 23434580 , 23570040 , 23706021 , 23842524 , 23979550 , 24117100 , 24255175 , 24393776 , 24532904 , 24672560 , 24812745 , 24953460 , 25094706 , 25236484 , 25378795 , 25521640 , 25665020 , 25808936 , 25953389 , 26098380 , 26243910 , 26389980 , 26536591 , 26683744 , 26831440 , 26979680 , 27128465 , 27277796 , 27427674 , 27578100 , 27729075 , 27880600 , 28032676 , 28185304 , 28338485 , 28492220 , 28646510 , 28801356 , 28956759 , 29112720 , 29269240 , 29426320 , 29583961 , 29742164 , 29900930 , 30060260 , 30220155 , 30380616 , 30541644 , 30703240 , 30865405 , 31028140 , 31191446 , 31355324 , 31519775 , 31684800 , 31850400 , 32016576 , 32183329 , 32350660 , 32518570 , 32687060 , 32856131 , 33025784 , 33196020 , 33366840 , 33538245 , 33710236 , 33882814 , 34055980 , 34229735 , 34404080 , 34579016 , 34754544 , 34930665 , 35107380 , 35284690 , 35462596 , 35641099 , 35820200 , 35999900 , 36180200 , 36361101 , 36542604 , 36724710 , 36907420 , 37090735 , 37274656 , 37459184 , 37644320 , 37830065 , 38016420 , 38203386 , 38390964 , 38579155 , 38767960 , 38957380 , 39147416 , 39338069 , 39529340 , 39721230 , 39913740 , 40106871 , 40300624 , 40495000 , 40690000 , 40885625 , 41081876 , 41278754 , 41476260 , 41674395 , 41873160 , 42072556 , 42272584 , 42473245 , 42674540 , 42876470 , 43079036 , 43282239 , 43486080 , 43690560 , 43895680 , 44101441 , 44307844 , 44514890 , 44722580 , 44930915 , 45139896 , 45349524 , 45559800 , 45770725 , 45982300 , 46194526 , 46407404 , 46620935 , 46835120 , 47049960 , 47265456 , 47481609 , 47698420 , 47915890 , 48134020 , 48352811 , 48572264 , 48792380 , 49013160 , 49234605 , 49456716 , 49679494 , 49902940 , 50127055 , 50351840 , 50577296 , 50803424 , 51030225 , 51257700 , 51485850 , 51714676 , 51944179 , 52174360 , 52405220 , 52636760 , 52868981 , 53101884 , 53335470 , 53569740 , 53804695 , 54040336 , 54276664 , 54513680 , 54751385 , 54989780 , 55228866 , 55468644 , 55709115 , 55950280 , 56192140 , 56434696 , 56677949 , 56921900 , 57166550 , 57411900 , 57657951 , 57904704 , 58152160 , 58400320 , 58649185 , 58898756 , 59149034 , 59400020 , 59651715 , 59904120 , 60157236 , 60411064 , 60665605 , 60920860 , 61176830 , 61433516 , 61690919 , 61949040 , 62207880 , 62467440 , 62727721 , 62988724 , 63250450 , 63512900 , 63776075 , 64039976 , 64304604 , 64569960 , 64836045 , 65102860 , 65370406 , 65638684 , 65907695 , 66177440 , 66447920 , 66719136 , 66991089 , 67263780 , 67537210 , 67811380 , 68086291 , 68361944 , 68638340 , 68915480 , 69193365 , 69471996 , 69751374 , 70031500 , 70312375 , 70594000 , 70876376 , 71159504 , 71443385 , 71728020 , 72013410 , 72299556 , 72586459 , 72874120 , 73162540 , 73451720 , 73741661 , 74032364 , 74323830 , 74616060 , 74909055 , 75202816 , 75497344 , 75792640 , 76088705 , 76385540 , 76683146 , 76981524 , 77280675 , 77580600 , 77881300 , 78182776 , 78485029 , 78788060 , 79091870 , 79396460 , 79701831 , 80007984 , 80314920 , 80622640 , 80931145 , 81240436 , 81550514 , 81861380 , 82173035 , 82485480 , 82798716 , 83112744 , 83427565 , 83743180 , 84059590 , 84376796 , 84694799 , 85013600 , 85333200 , 85653600 , 85974801 , 86296804 , 86619610 , 86943220 , 87267635 , 87592856 , 87918884 , 88245720 , 88573365 , 88901820 , 89231086 , 89561164 , 89892055 , 90223760 , 90556280 , 90889616 , 91223769 , 91558740 , 91894530 , 92231140 , 92568571 , 92906824 , 93245900 , 93585800 , 93926525 , 94268076 , 94610454 , 94953660 , 95297695 , 95642560 , 95988256 , 96334784 , 96682145 , 97030340 , 97379370 , 97729236 , 98079939 , 98431480 , 98783860 , 99137080 , 99491141 , 99846044 , 100201790 , 100558380 , 100915815 , 101274096 , 101633224 , 101993200 , 102354025 , 102715700 , 103078226 , 103441604 , 103805835 , 104170920 , 104536860 , 104903656 , 105271309 , 105639820 , 106009190 , 106379420 , 106750511 , 107122464 , 107495280 , 107868960 , 108243505 , 108618916 , 108995194 , 109372340 , 109750355 , 110129240 , 110508996 , 110889624 , 111271125 , 111653500 , 112036750 , 112420876 , 112805879 , 113191760 , 113578520 , 113966160 , 114354681 , 114744084 , 115134370 , 115525540 , 115917595 , 116310536 , 116704364 , 117099080 , 117494685 , 117891180 , 118288566 , 118686844 , 119086015 , 119486080 , 119887040 , 120288896 , 120691649 , 121095300 , 121499850 , 121905300 , 122311651 , 122718904 , 123127060 , 123536120 , 123946085 , 124356956 , 124768734 , 125181420 , 125595015 , 126009520 , 126424936 , 126841264 , 127258505 , 127676660 , 128095730 , 128515716 , 128936619 , 129358440 , 129781180 , 130204840 , 130629421 , 131054924 , 131481350 , 131908700 , 132336975 , 132766176 , 133196304 , 133627360 , 134059345 , 134492260 , 134926106 , 135360884 , 135796595 , 136233240 , 136670820 , 137109336 , 137548789 , 137989180 , 138430510 , 138872780 , 139315991 , 139760144 , 140205240 , 140651280 , 141098265 , 141546196 , 141995074 , 142444900 , 142895675 , 143347400 , 143800076 , 144253704 , 144708285 , 145163820 , 145620310 , 146077756 , 146536159 , 146995520 , 147455840 , 147917120 , 148379361 , 148842564 , 149306730 , 149771860 , 150237955 , 150705016 , 151173044 , 151642040 , 152112005 , 152582940 , 153054846 , 153527724 , 154001575 , 154476400 , 154952200 , 155428976 , 155906729 , 156385460 , 156865170 , 157345860 , 157827531 , 158310184 , 158793820 , 159278440 , 159764045 , 160250636 , 160738214 , 161226780 , 161716335 , 162206880 , 162698416 , 163190944 , 163684465 , 164178980 , 164674490 , 165170996 , 165668499 , 166167000
        };
    return(arr[n-3]);
}

//Creates all c(n, 3) combinations (NOT PERMUTATIONS!!)
void generatecombo(vector<Combination> &combo, vector<int> xpoints, vector<int> ypoints, long long unsigned int size, int N){
    long long unsigned int temp = 0;
    for (int i =0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            for (int k = j + 1; k < N; k++){
                int det = xpoints[i]*ypoints[j] + ypoints[i]*xpoints[k] + xpoints[j]*ypoints[k] - xpoints[k]*ypoints[j] - ypoints[k]*xpoints[i] - xpoints[j]*ypoints[i];
                if (det == 0){
                    combo[temp].xcoords.push_back(xpoints[i]);
                    combo[temp].ycoords.push_back(ypoints[i]);
                    
                    combo[temp].xcoords.push_back(xpoints[j]);
                    combo[temp].ycoords.push_back(ypoints[j]);

                    combo[temp].xcoords.push_back(xpoints[k]);
                    combo[temp].ycoords.push_back(ypoints[k]); 
                }
                else{
                    combo.erase(combo.begin() + temp);
                    temp--;
                }
                //printvector(combo[temp].xcoords, combo[temp].ycoords);
                temp++;
                if (temp == size){
                    //cout<<"Generated combinations"<<endl;
                    return;
                }
            }
        } 
    }

}

/**
 * @brief  Removes duplicate elements from a vector
 * @note   
 * @param  *points: 
 * @retval None
 */
void removeduplicates(vector<int> &xcoords, vector<int> &ycoords){
    for (int i = 0; i < xcoords.size(); i++){
        for (int j = 0; j < xcoords.size()-1; j++){
            if (i == j){
                j++;
            }
            if (xcoords[i] == xcoords[j] && ycoords[i] == ycoords[j]){
                //printvector(xcoords, ycoords);
                xcoords.erase(xcoords.begin() + j);
                ycoords.erase(ycoords.begin() + j);
                j--;
            }
        }
    }

}

/**
 * @brief  Take two collinear options and see if they are also collinear
 * @note   
 * @param  *combo: 
 * @retval None
 */
void combine(vector<Combination> &combo){
    for (int i = 0; i < combo.size(); i++){
        for (int j = 0; j < combo.size(); j++){
            if (i == j){
                j++;
            }
            //If same line, then add points to the first combination
            if (combo[i].slope == combo[j].slope && combo[i].intercept == combo[j].intercept){
                for (int k = 0; k < combo[j].xcoords.size(); k++){
                    //cout<<"Trying pushback"<<endl;
                    combo[i].xcoords.push_back(combo[j].xcoords[k]);
                    combo[i].ycoords.push_back(combo[j].ycoords[k]);
                }
                //remove duplicate points in first combination
                //cout<<"Removing duplicates"<<endl;
                //printvector(combo[i].xcoords, combo[i].ycoords);
                removeduplicates(combo[i].xcoords, combo[i].ycoords);
                //printvector(combo[i].xcoords, combo[i].ycoords);
                //Delete other (duplicate) combination
                //cout<<"deleting duplicates"<<endl;
                //cout<<combo.size()<<i<<j<<endl;
                if (combo.size() == 1){
                    cout<<"size = 1"<<endl;
                    return;
                }
                int temp = combo.size();
                combo.erase(combo.begin() + j);
                combo.resize(temp-1);
                //cout<<"deleted duplicates"<<endl;
                j--;
            }

        }
    }
    //cout<<combo.size()<<endl;
}

//Basic slope formula
double slopecalc(vector<int> xcoords, vector<int> ycoords, int N){
    //for undefined slope
    if (xcoords[0] == xcoords[1]){
        return(3*N);
    }
    else{
        double y1 = ycoords[1];
        double y0 = ycoords[0];
        double x1 = xcoords[1];
        double x0 = xcoords[0];
        double temp = (y1 - y0) / (x1 - x0);
        return(temp);
    }
}

//Basic intercept formula
double interceptcalc(vector<int> xcoords, vector<int> ycoords, double slope, int N){
    //for undefined slope, simply return the shared x value
    if (slope == 3 * N){
        return(xcoords[0]);
    }
    else{
        double s = slope;
        double y = ycoords[0];
        double x = xcoords[0];
        double temp = y - (s * x);
        return(temp);
    }
}

//Prints out tuples
void printvector(vector<int> xcoords, vector<int> ycoords){
    for (int i=0; i < xcoords.size(); i++){
        cout<<"("<<xcoords[i]<<", "<<ycoords[i]<<"), ";
    }
    cout<<endl;

}

//Generates article of a number (1 = st, 2 = nd, 3 = rd, etc.)
string article(int a){
    if (a == 11 || a == 12 || a == 13){
        return("th");
    }
    int mod = a % 10;
    string article;
    string arr[] = {"st", "nd", "rd", "th", "th", "th", "th", "th", "th", "th"};
    article = arr[a];
    return(article);
}   

int generaterandom(int range){
    random_device rd;
    mt19937 gen(rd());
    // perform 4 trials, each succeeds 1 in 2 times
    //std::binomial_distribution<> d(4, 0.5);
    uniform_int_distribution<int> d(-range,range);

    return d(gen);
}
/*
double everything(int N, char random){
    //Generates random seed
    srand((unsigned) time(NULL));
    int xgridsize;
    int ygridsize;
    long long unsigned int tempo = (long long unsigned) N;
    long long unsigned int fact = factorial(tempo);
    //cout<<factorial(tempo)<<"\n"<<fact<<endl;
    vector<int> xpoints(N);
    vector<int> ypoints(N);
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
                        cout<<"retrying"<<endl;
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
    clock_t t5;
    t5 = clock(); 
    //initializes combinations
    vector<Combination> nCr;
    for (long long unsigned int i=0; i < fact; i++){
        nCr.push_back(Combination());
    }
    // Generates all combinations
    generatecombo(nCr, xpoints, ypoints, fact, N);



    //Case if all points have det != 0
    if (nCr.size() == 0){
        t5 = clock() - t5;
        double time_taken5 = ((double)t5)/CLOCKS_PER_SEC;
        return(time_taken5);
    }

    //Calculates slopes and intercepts
    for (int i=0; i < nCr.size(); i++){
        nCr[i].slope = slopecalc(nCr[i].xcoords, nCr[i].ycoords, N);
        nCr[i].intercept = interceptcalc(nCr[i].xcoords, nCr[i].ycoords, nCr[i].slope, N);
    }
    //Combines all combinations into only those with unique slope and intercept
    combine(nCr);
    //Evaluates sizes
    int largest = 0;
    
    for (int i=0; i < nCr.size(); i++){
        if(nCr[i].xcoords.size() > largest){
            largest = nCr[i].xcoords.size();
        }
    }

    t5 = clock() - t5;
    double time_taken5 = ((double)t5)/CLOCKS_PER_SEC;

    return(time_taken5);
}
*/