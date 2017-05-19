#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	//inputting board size and #obstacles...
	int n,k,slopes;
	cin  >> n >> k;

	// inputting queen's position...
	int posx,posy;
	cin >> posx >> posy;

	//declaring maximum moves...
	int l = posx;         //allowed left moves
	int r = n - posx;     //allowed right moves
	int d = posy;         //allowed down direction moves
	int u = n - posy;     //allowed up direction moves

	//getting the co-ordinates of the obstacles...
	vector <pair<int,int>> obs;
	pair<int,int> pairobs;

    //making the vector for slopes and Sl.no....
	vector <pair<int,int> > slope;
	pair <int,int> pairslope;

    //vector for closest obstacles...
    vector <int> closest;
    //initializing this...
    for(int i=0;i<8;i++){
        closest.push_back(0);
    }

	for(int i=0;i<k;i++){
		int posx1 = 0, posy1 = 0;
		cin >> posx1 >> posy1;
		//declaring obstacle positions wrt origin(which is [psox,posy])...
		/*posx1 -= posx;
		posy1 -= posy;*/

        //cout << posx1 << posy1 << endl;
		//pushing positions into obs(which stands for obsatcles).
		pairobs.first = posx1;
		pairobs.second = posy1;
		obs.push_back(pairobs);

		//getting the slope right...
        if(posx1){
  		    slopes = (posy1 - posy)/(posx1-posx);
					if(posx1 < posx)
						slopes = -99999.99;
		}
        else {
						if(posy1 > posy)
            slopes = +99999;
						else
						slopes = -99999;
        }
        pairslope.first = slopes;
				pairslope.second = i;
				slope.push_back(pairslope);

	}

	//some thinking...

	/*There are eight lines to the problem... So, what do we do now?
	1. Obviously, there is an upper bound to the number of squares the queen
	move to..
	2. By placing obstacles, we're lowering the # of those squares..
	3. Each obstacle will reduce the squares in the corresponding direction.
	4. If we can find all the obstacles closest to the queen in each direct-
	-ion, then the problem becomes very simple.
	*/

		int sum = 0;
		int sumr = n;
		int suml = posx - 1;
		int sumd = n;
		int sumu = n;
		int sumru = n;
		int sumrd = n;
		int sumlu = n;
		int sumld = n;
    if(obs.size()){
       	for(int i=0;i<obs.size(); i++){
						// in the right direction...
						if(slope[i].first == 0) {
							if((obs[i].first - posx) < sumr){
								sumr = obs[i].first - posx;
							}
						}
						// the up direction...
						else if(slope[i].first == 99999){
							if((obs[i].second - posy) < sumu){
								sumu = obs[i].second - posy;
							}
						}
						//the left direction...
						else if(slope[i].first == -99999.99){
							if((posx - obs[i].first) < suml){
								sumu = posx - obs[i].first;
							}
						// the up direction...
						else if(slope[i].first == -99999){
								if((posy - obs[i].second) < sumd){
									sumu = obs[i].second - posy;
								}
							}

        }
    }
    else {
				sumr = n - posx;
				suml = posx -1;
				sumu = n - posy;
				sumd = posy - 1;
				sumru = min(sumr,sumu);
				sumrd = min(sumr,sumd);
				sumld = min(sumd,suml);
				sumlu = min(sumu,sumu);
    }
		sum = sumr + suml + sumd + sumu + sumld + sumlu + sumru + sumrd;
		cout << sum;
	return 0;
}
