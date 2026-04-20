/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 02 – Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Bismar Alwi Khadavi (13224016)
 *   Nama File           : soal1.c
 *   Deskripsi           : Kode untuk mengisi data yang hilang dengan merata-ratakan nilai sebelum dan sesudah terdekat.
 *                         Jika semua data hilang, ganti semuanya dengan 0.
 *                         Max sum untuk jumlah maksimum sub-array (yang berurutan) dalam array
 */

 #include <stdio.h>
 #include <string.h>
 
 int semuaHilang(int data[], int N, int start) {
    for(int i=start; i<N; i++){
        if(data[i]!=-1){
            return 0;
        }
    }
    return 1;
 }

 int main() {
    int N;
    scanf("%d", &N);
    int data[N];
    for(int i=0; i<N; i++) {
        scanf("%d", &data[i]);
    }

    for(int i=0; i<N; i++) {
        if(N==1 && data[i]==-1){
            data[i] = 0;
        }
        if(data[i]==-1){
            if(data[i-1]!=-1 && i!=0 && data[N-1]!=-1){ //kiri ada, kanan hilang (tidak termsuk pojok kanan hilang)
                for(int j=i+1; j<N; j++){
                    if(data[j]!=-1 && j!=N && data[i-1] > 0 && data[j] > 0){
                        data[i] = (data[i-1]+data[j])/2;
                        break;
                    }
                    else if(data[j]!=-1 && j!=N && data[i-1] <= 0 && data[j] <= 0){
                        data[i] = (data[i-1]+data[j]-1)/2;
                        break;
                    }
                    else if(data[j]!=-1 && j!=N && data[i-1] > 0 && data[j] < 0){
                        data[i] = (data[i-1]+data[j]-0.5)/2;
                        break;
                    }
                    else if(data[j]!=-1 && j!=N && data[i-1] < 0 && data[j] > 0){
                        data[i] = (data[i-1]+data[j]+0.5)/2;
                        break;
                    }
                }
            }
            else if(i==0){ //data hilang di paling kiri
                for(int j=i+1; j<N; j++){
                    if(data[j]!=-1){
                        data[i] = data[j];
                        break;
                    }
                }
            }
            else if(i==N-1){ //data hilang di paling kanan
                for(int j=i-1; j>=0; j--){
                    if(data[j]!=-1){
                        data[i] = data[j];
                        break;
                    }
                    else{
                        for(int k=i-1; k>=0; k--){
                            if(data[k]!=-1){
                                data[j] = data[k];
                                break;
                            }
                        }
                    }
                }
            }
            else if(semuaHilang(data, N, 0)==1){ //semua data hilang
                for(int j=0; j<N; j++){
                    data[j] = 0;
                }
            }
        }
    }

    int sumSementara;
    int sumMax = data[0];
    //hitung subarray berurutan dengan jumlah maksimum dengan looping berkali-kali
    for(int i=0; i<N; i++) {
        sumSementara = 0;
        for(int j=i; j<N; j++) {
            sumSementara += data[j];
            if((sumSementara > sumMax)&& data[j]>=0)  {
                sumMax = sumSementara;
            }
            //jika sum sementara sudah negatif, cek subarray berikutnya
            else if(data[j] < 0) {
                break;
            }
        }
    }
    if(sumMax < 0){
        for(int i=0; i<N; i++){
            sumSementara = data [i];
            if(sumSementara > sumMax){
                sumMax = sumSementara;
            }
        }
    }

    printf("RECOVERED ");
    for(int i=0; i<N-1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d", data[N-1]);
    printf("\nMAX_SUM %d\n", sumMax);

 }
 
