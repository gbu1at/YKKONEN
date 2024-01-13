#include <bits/stdc++.h>
#include "LZ77/LZ77.cpp"
#include "HuffmanCode/HuffmanCode.cpp"


std::string randStr(int n) {
    std::string res;
    for (int i = 0; i < n; ++i) {
        char c = rand() % 10 + 97;
        res += toString(c);
    }
    return res;
}



int main() {
    
    #ifdef TIME
        int start = clock();
    #endif

    std::string t = randStr(100000); 

    std::cout << "---- START HUFFMAN COMPRESS ----\n";

    HuffmanCode hc = HuffmanCode(t);
    std::string huffmanCompressT = hc.huffmanCodeFirst();

    std::cout << "---- FINISH HUFFMAN COMPRESS ----\n";

    //----------------------------------------

    std::cout << "---- START BUILD LZ77 ----\n";
    
    std::string lz77Compress = LZ77<std::string>().compress(huffmanCompressT);
    
    std::cout << "---- FINISH BUILD LZ77 ---\n";
    
    //-----------------------------------------
    
    std::cout << "-----START CHECK CORRECT DECODER----\n";

    assert(hc.decoder(decoder(lz77Compress)) == t);

    std::cout << "-----DECODER IS CORRECT----\n";

    std::cout << (t.size() * 8) << " / " << lz77Compress.size() << '\n';

    
    #ifdef TIME
        int finish = clock();
        std::cout << (finish - start) / (double) CLOCKS_PER_SEC << '\n';
    #endif

	return 0;
}