#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(limpiarAudioTEST, audioSinOutliers){
    audio a = {1};
    audio outliers;
    int profundidad = 6;
    audio audioEsperado = {1};
    audio outliersEsperado;

    limpiarAudio(a, profundidad, outliers);

    ASSERT_VECTOR(a, audioEsperado);
    ASSERT_VECTOR(outliers, outliersEsperado);
}

TEST(limpiarAudioTEST, audio19elemSinOutliers){
    audio a = {9,8,5,3,4,7,5,1,8,9,99,15,67,54,62,14,23,12,54};
    audio outliers;
    int profundidad = 7;
    audio audioEsperado = {9,8,5,3,4,7,5,1,8,9,99,15,67,54,62,14,23,12,54};
    audio outliersEsperado;

    limpiarAudio(a, profundidad, outliers);

    ASSERT_EQ(a, audioEsperado);
    ASSERT_EQ(outliers, outliersEsperado);
}

TEST(limpiarAudioTEST, 32elemntosCon1OutlierEnElMedioAprox){
    audio a = {9,8,5,3,4,7,5,1,8,9,9,0,-67,51,62,14,23,12,8,32,43,15,4,-91,0,9,8,31,12,23,0,1};
    audio outliers;
    int profundidad = 7;
    audio audioEsperado = {9,8,5,3,4,7,5,1,8,9,9,0,-67,51,32,14,23,12,8,32,43,15,4,-91,0,9,8,31,12,23,0,1};
    audio outliersEsperado ={14};

    limpiarAudio(a, profundidad, outliers);

    ASSERT_EQ(a, audioEsperado);
    ASSERT_EQ(outliers, outliersEsperado);
}
TEST(limpiarAudioTEST, 100elemntosDel0al100Con4utlierSinNoOutliersRight){
    audio a = construir_vector(100,"asc");
    audio outliers;
    int profundidad = 8;
    audio audioEsperado = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,95,95,95,95};
    audio outliersEsperado ={96,97,98,99};

    limpiarAudio(a, profundidad, outliers);

    ASSERT_EQ(a, audioEsperado);
    ASSERT_EQ(outliers, outliersEsperado);
}



TEST(limpiarAudioTEST, 100elemntosDel100al0Con4utlierSinNoOutliersLeft){
    audio a = construir_vector(100,"desc");
    audio outliers;
    int profundidad = 8;
    audio audioEsperado = {95,95,95,95,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    audio outliersEsperado ={0,1,2,3};

    limpiarAudio(a, profundidad, outliers);

    ASSERT_EQ(a, audioEsperado);
    ASSERT_EQ(outliers, outliersEsperado);
}
