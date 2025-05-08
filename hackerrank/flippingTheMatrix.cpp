int flippingMatrix(vector<vector<int>> matrix) {
    int size = matrix.size();
    int sum(0);
    for (int i = 0; i != size/2; ++i)
        for (int j = 0; j != size/2; ++j)
            sum += max({matrix[i][j], 
                matrix[i][size - j - 1], 
                matrix[size - i - 1][size - j - 1],
                matrix[size - i - 1][j]}); 
                //{initializer_list} or std::max won't work
            
    return sum;
}
