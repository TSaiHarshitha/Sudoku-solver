#include <iostream>
#include <vector>
using namespace std;

bool tests_passed(vector<vector<int>>& sudoku, int row, int column, int value) {
    
    //checking if any cell in the row has value equal to variable "value".
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == value)
            return false;
    }

    //checking if any cell in the column has value equal to variable "value".
    for (int j = 0; j < 9; j++) {
        if (sudoku[j][column] == value)
            return false;
    }

    //checking if any cell in the sub grid has value equal to variable "value".
    int subgridRow = 3 * (row / 3);
    int subgridCol = 3 * (column / 3);
    
    for (int i = subgridRow; i < subgridRow + 3; i++) {
        for (int j = subgridCol; j < subgridCol + 3; j++) {
            
            if (sudoku[i][j] == value)
                return false;
        }
    }

    return true;
}




bool sudoku_solver(vector<vector<int>>& sudoku) {
    
    // iterating over the sudoku 
    for (int row = 0; row < 9; row++) {
        for (int column = 0; column < 9; column++) {
            
            if (sudoku[row][column] == 0) {
                
                for (int value = 1; value <= 9; value++) {
                    
                    if (tests_passed(sudoku, row, column, value)) {
                        sudoku[row][column] = value;
                        
                        if (sudoku_solver(sudoku)) {
                            return true;
                        }
                        sudoku[row][column] = 0;  // Backtrack if the current value does not lead to a solution
                    }
                }
                return false;  // no valid value is found for cell 
            }
        }
    }
    return true;  // If all cells are filled i.e a solution is found :) 
}

int main(){
    
    // storing given sudoku values in a vector "sudoku"
	vector<vector<int>>sudoku(9);
	
	for(int i = 0 ; i < 9 ; i++)
	    for(int j = 0 ; j < 9 ; j++){
	        
	        int a;
	        cin>>a;
	        sudoku[i].push_back(a);
	    }
	    
	 // printing the solved sudoku 
	 if(sudoku_solver(sudoku)){
	     
	     for(int i = 0 ; i < 9 ; i++){
	         for(int j = 0 ; j< 9 ; j++){
	             cout<<sudoku[i][j]<<" ";
	         }
	         cout<<"\n";
	     }
	 }
	 else cout<<"No Solution Possible\n";

	return 0;
}
