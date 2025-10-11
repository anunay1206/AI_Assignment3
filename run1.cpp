#include<bits/stdc++.h>
using namespace std;

int generateID(int cell)
{
    return 0;
}

int main() {

	int scenario;
    cin>>scenario;
    
    int S,N,M,K,J;
    cin>>S>>N>>M>>K>>J;

    vector<pair<int,int>> start_pairs;
    vector<pair<int,int>> end_pairs;
    vector<int> clause;
    vector<vector<int>>allClauses;

    int metro_line_per_cell[M][N][K];

    for(int i= 0; i < K; i++) 
    {
        int start_x, start_y, end_x, end_y;
        cin>>start_x>>start_y>>end_x>>end_y;
        int id_start = generateID(metro_line_per_cell[start_x][start_y][i]);
        clause.push_back(id_start);
        int id_end = generateID(metro_line_per_cell[end_x][end_y][i]);
        clause.push_back(id_end);

        start_pairs.push_back({start_x, start_y});
        end_pairs.push_back({end_x,end_y});
    }
    allClauses.push_back(clause); 

  // unordered_map<vector<int>,int>>storeID;


    for(int i= 0; i < M; i++) 
    {
    	for(int j = 0; j < N; j++)
        {
         	for(int l = 0; l <= K; l++) 
            {
              int int_id = generateID(metro_line_per_cell[i][j][l]);
              // storeID[metro_line_per_cell[i][j][l]] = int_id;
              clause.push_back(int_id);
              
            }
          allClauses.push_back(clause);
          clause.clear();
         
         for(int l = 0; l < K; l++) 
         {
           for(int m = l+1; m <=K; m++)
           {
             int int_id1 = generateID(metro_line_per_cell[i][j][l]);
             // storeID[metro_line_per_cell[i][j][l]] = int_id;
             clause.push_back(-int_id1);
             
             int int_id2 = generateID(metro_line_per_cell[i][j][m]);
             // storeID[metro_line_per_cell[i][j][l]] = int_id;
             clause.push_back(-int_id2);
           }
         }
          
          allClauses.push_back(clause);
        }
    }
  int direction_per_cell[M][N][5];
  for(int i=0;i<M;i++)
  {
    for(int j=0;j<N;j++)
    {
      for(int d = 0;d<5;d++)
      {
        int int_id = generateID(direction_per_cell[i][j][d]);
        clause.push_back(int_id);
      }
      
      allClauses.push_back(clause);
      clause.clear();
      
      for(int d = 0;d<5;d++)
      {
        for(int p=d+1;p<5;p++)
        {
        	int int_id1 = generateID(direction_per_cell[i][j][d]);
        	clause.push_back(-int_id1);
          
         	int int_id2 = generateID(direction_per_cell[i][j][p]);
            clause.push_back(-int_id2);
        }
      }
      allClauses.push_back(clause);
    }
  }



    return 0;
}