public class APSP 
{
    public static void printSolution(int cost[][], int n) 
    { 
        final int I = 99999;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            { 
                if (cost[i][j] == I) 
                {
                    System.out.print("Inf ");
                } 
                else 
                {
                    System.out.print(cost[i][j] + " ");
                }
            }
            System.out.println();
        }
    
    }

    public static void main(String[] args) 
    { 
        final int I = 99999;
        int matrix[][] = { 
            { 0, 5, I, 10 },
            { I, 0, 3, I },
            { I, I, 0, 1 },
            { I, I, I, 0 } 
        };
        int n = matrix.length;
        int cost[][] = new int[n][n];
        // Floyd Warshall Algorithm 
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            { 
                cost[i][j] = matrix[i][j];
            }
        }

        for (int k = 0; k < n; k++) 
        {
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (cost[i][k] + cost[k][j] < cost[i][j])
                    {
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }
        printSolution(cost, n);
    }
}