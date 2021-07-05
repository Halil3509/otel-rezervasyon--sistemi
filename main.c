#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool   int
#define true   (1)
#define false  (0)

typedef struct
{
  int GtarihGun;
  int GtarihAy;
  int GtarihYil;
  int DtarihGun;
  int DtarihAy;
  int DtarihYil;
  char isim[50];
  char soyisim[50];
}oda;



int main()
{
    //Tanımlama bölümü
    int secim,i,nowDay,nowMonth,nowYear,tempi;
    int odaUcretleri[8]={0,100,150,200,250,300,350,400};
    char odaIsimleri[10][7]={"","oda1","oda2","oda3","oda4","oda5","oda6","oda7"},odaSecim[10],odaDoluBosTegit[10],silmeOda[15];
    bool kontrol=false,kontrol2=false,rezTamamlama=false;
    char baskaIslem[20];

    //program giriş kısmı
    oda odalar[8];
    oda odaKontrol;
    oda *podalar[8];
    oda odaBosDoluKontrol[8];
    for(i=0;i<8;i++)
    {
        odalar[i].DtarihAy=0;
        odalar[i].DtarihGun=0;
        odalar[i].DtarihYil=0;
        odalar[i].GtarihAy=0;
        odalar[i].GtarihGun=0;
        odalar[i].GtarihYil=0;
        strcpy(odalar[i].isim,"bos");
        strcpy(odalar[i].soyisim,"bos");
        podalar[i]=&odalar[i];

    }
    genelTekrar:
    printf("\n\n");
    printf("1-Bos odalari goster\n");
    printf("2-Rezervasyon islemi\n");
    printf("3-Rezervasyon iptal islemi\n");
    printf("4-Rezervasyonlari goster\n");
    printf("Birini seciniz:");
    scanf("%d",&secim);
    if(secim==1){}
    else if(secim==2){}
    else if(secim==3){}
    else if(secim==4){}
    else
    {
        printf("Gecersiz giris. Lutfen tekrar deneyiniz.\n");
        goto genelTekrar;
    }


    switch(secim)
    {
        //tarihlerre göre boş odaları gösterme kontrol kısmı
        case 1:
        {
          printf("gidis gun ay yil:");
          scanf("%d %d %d",&odaKontrol.GtarihGun,&odaKontrol.GtarihAy,&odaKontrol.GtarihYil);
          printf("donus gun ay yil:");
          scanf("%d %d %d",&odaKontrol.DtarihGun,&odaKontrol.DtarihAy,&odaKontrol.DtarihYil);
          for(i=0;i<8;i++)
          {
              if(odaKontrol.GtarihAy==odalar[i].DtarihAy)
                 {
                     if(odaKontrol.GtarihGun > odalar[i].GtarihGun &&odaKontrol.GtarihGun>odalar[i].DtarihGun) /* (odaKontrol.DtarihGun <odalar[i].DtarihGun && odaKontrol.DtarihGun<odalar[i].GtarihGun)) */
                    {
                       printf("%s bos\n",odaIsimleri[i]);
                    }
                    else{
                        printf("oda dolu");
                        break;
                    }
                 }
              else if(odaKontrol.GtarihAy < odalar[i].DtarihAy &&  odaKontrol.GtarihAy < odalar[i].GtarihAy)
              {
                  printf("%s bos\n",odaIsimleri[i]);

              }
              else if(odaKontrol.GtarihAy <odalar[i].DtarihAy && odaKontrol.GtarihAy > odalar[i].GtarihAy)
              {

                  if(odaKontrol.DtarihGun > odalar[i].GtarihGun)
                  {
                      printf("%s bos \n",odaIsimleri[i]);
                  }
                  else{
                    printf("oda dolu");
                    break;
                  }
              }
              else if(odaKontrol.GtarihAy >odalar[i].DtarihAy )
              {
                  printf("%s bos\n",odaIsimleri[i]);
              }
              else
              {
                  printf("oda dolu");
                  break;
              }
          }
           printf("Baska islem yapmak ister misiniz:");
                scanf("%s",&baskaIslem);
                if(strcmp("evet",baskaIslem)==0)
                {
                    goto genelTekrar;
                }
                else
                {
                    break;
                }
            break;
        }
        //Boş odalar seçilip rezervasyon yaptırma kısmı
        case 2:
            {
                printf("***REZERVASYON BOLUMUNE HOS GELDINIZ\n");
                odaBosTekrar:
                printf("oda seciniz:");
                scanf("%s",&odaSecim);
                for(i=0;i<8;i++)
                {
                    if(strcmp(odaSecim,odaIsimleri[i])==0)
                    {
                        printf("oda bulundu.\n");
                        tempi=i;
                        kontrol2=true;
                    }
                }
                if(kontrol2==false)
                {
                    printf("oda ismi bulunamadi. Lutfen tekrar deniyiniz.\n");
                    goto odaBosTekrar;
                }
                            printf("isminizi giriniz:");
                            scanf("%s",&odalar[tempi].isim);
                            printf("soyisminizi giriniz:");
                            scanf("%s",&odalar[tempi].soyisim);
                            tarihTekrar:
                            printf("giris tarihinizi giriniz( g a yyyy):");
                            scanf("%d %d %d",&odaBosDoluKontrol[tempi].GtarihGun,&odaBosDoluKontrol[tempi].GtarihAy,&odaBosDoluKontrol[tempi].GtarihYil);
                            printf("donus tarihinizi giriniz(g a yyyy):");
                            scanf("%d %d %d",&odaBosDoluKontrol[tempi].DtarihGun,&odaBosDoluKontrol[tempi].DtarihAy,&odaBosDoluKontrol[tempi].DtarihYil);
                            if(odaBosDoluKontrol[tempi].DtarihAy<odaBosDoluKontrol[tempi].GtarihAy)
                            {
                                printf("giris tarihi donus tarihinden daha ileri olamaz. Lutfen tekrar deneyiniz.\n");
                                goto tarihTekrar;

                            }
                            else if(odaBosDoluKontrol[tempi].DtarihAy==odaBosDoluKontrol[tempi].GtarihAy && odaBosDoluKontrol[tempi].DtarihGun<odaBosDoluKontrol[tempi].GtarihGun)
                            {
                                printf("giris tarihi donus tarihinden daha ileri olamaz. Lutfen tekrar deneyiniz.\n");
                                goto tarihTekrar;

                            }
                            else if(odaBosDoluKontrol[tempi].GtarihYil>odaBosDoluKontrol[tempi].DtarihYil)
                            {
                                printf("giris tarihi donus tarihinden daha ileri olamaz. Lutfen tekrar deneyiniz.\n");
                                goto tarihTekrar;
                            }
                            else if(odaBosDoluKontrol[tempi].GtarihGun>odaBosDoluKontrol[tempi].DtarihGun)
                            {
                                printf("giris tarihi donus tarihinden daha ileri olamaz. Lutfen tekrar deneyiniz.\n");
                                goto tarihTekrar;
                            }
                            else{
                            rezTamamlama=true;
                            }

                            ayif(odaBosDoluKontrol[tempi].GtarihAy==odalar[tempi].DtarihAy)
                            {
                                if(odalar[tempi].GtarihGun<odaBosDoluKontrol[tempi].DtarihGun && odalar[tempi].DtarihGun>odalar[tempi].DtarihGun);
                                {
                                    printf("Bu zaman araliginda sectiginiz oda doludur.\n");
                                    printf("yeni bir tarih giriniz. (isterseniz de bos odalara bakabilirsiniz)\n");
                                    goto tarihTekrar;
                                }


                            }

                            else if(odaBosDoluKontrol[tempi].GtarihAy<odalar[tempi].DtarihAy)
                            {
                                if(odaBosDoluKontrol[tempi].DtarihGun>odalar[tempi].GtarihGun)
                                {
                                    printf("Bu zaman araliginda sectiginiz oda doludur.\n");
                                    printf("yeni bir tarih giriniz. (isterseniz de bos odalara bakabilirsiniz)\n");
                                    goto tarihTekrar;
                                }
                            }
                            else if(odaBosDoluKontrol[tempi].GtarihAy<odalar[tempi].GtarihAy)
                            {
                                if(odaBosDoluKontrol[tempi].DtarihGun>odalar[tempi].GtarihGun)
                                {
                                    printf("Bu zaman araliginda sectiginiz oda doludur.\n");
                                    printf("yeni bir tarih giriniz. (isterseniz de bos odalara bakabilirsiniz)\n");
                                    goto tarihTekrar;
                                }
                            }
                            else
                            {
                                rezTamamlama=true;
                            }
                           if(rezTamamlama==true)
                           {
                               printf("Rezervasyon isleminiz gerceklesmistir.\n");
                               odalar[tempi].GtarihGun=odaBosDoluKontrol[tempi].GtarihGun;
                               odalar[tempi].GtarihAy=odaBosDoluKontrol[tempi].GtarihAy;
                               odalar[tempi].GtarihYil=odaBosDoluKontrol[tempi].GtarihYil;
                               odalar[tempi].DtarihGun=odaBosDoluKontrol[tempi].DtarihGun;
                               odalar[tempi].DtarihAy=odaBosDoluKontrol[tempi].DtarihAy;
                               odalar[tempi].DtarihYil=odaBosDoluKontrol[tempi].DtarihYil;
                            FILE *dosya;
                            dosya=fopen("hotel_rezervasyon.txt","w+");
                            fprintf(dosya,"isim:%s\n",odalar[tempi].isim);
                            fprintf(dosya,"soyisim:%s\n",odalar[tempi].soyisim);
                            fprintf(dosya,"giris tarihi: %d %d %d\n",odalar[tempi].GtarihGun,odalar[tempi].GtarihAy,odalar[tempi].GtarihYil);
                            fprintf(dosya,"donus tarihi: %d %d %d\n",odalar[tempi].DtarihGun,odalar[tempi].DtarihAy,odalar[tempi].DtarihYil);
                            fprintf(dosya,"----------------------------");
                            fclose(dosya);
                           }

                printf("Baska islem yapmak ister misiniz:");
                scanf("%s",&baskaIslem);
                if(strcmp("evet",baskaIslem)==0)
                {
                    goto genelTekrar;
                }
                else
                {
                    break;
                }
                break;
            }

            //rezervasyon iptal işlemi
        case 3:
            {
                            printf("***IPTAL ETME BOLUMU***\n");
                            odaSilmeTekrar:
                            printf("silmek istediginiz odayi seciniz:\n");
                            scanf("%s",&silmeOda);
                            for(i=0;i<8;i++)
                            {
                                if(strcmp(odaIsimleri[i],silmeOda)==0)
                                {
                                    kontrol=true;
                                }
                            }
                            if(kontrol==false)
                            {
                                printf("oda ismi bulunamadi.Lutfen tekrar deneyiniz.\n");
                                goto odaSilmeTekrar;
                            }

                            printf("bugunun tarihini giriniz(g a yyyy):");
                            scanf("%d %d %d",&nowDay,&nowMonth,&nowYear);
                            if(odalar[i].GtarihGun-nowDay<=1)
                            {
                                printf("son 24 saat iptale izin verilmemektedir maalesef :(");
                                break;
                            }
                            isimtekrar:
                            printf("isminizi giriniz:");
                            scanf("%s",&odalar[i].isim);
                            printf("soyisminizi giriniz:");
                            scanf("%s",&odalar[i].soyisim);
                            odalar[i].DtarihAy=0;
                            odalar[i].DtarihGun=0;
                            odalar[i].DtarihYil=0;
                            odalar[i].GtarihAy=0;
                            odalar[i].GtarihYil=0;
                            printf("silme isleminiz gerceklesti");
                printf("Baska islem yapmak ister misiniz:");
                scanf("%s",&baskaIslem);
                if(strcmp("evet",baskaIslem)==0)
                {
                    goto genelTekrar;
                }
                else
                {
                    break;
                }
                break;
            }
        case 4:
            {
                printf("oda ismi     isim    soyisim        giris tarih        cikis tarih\n");
                printf("---------    ----    -------        ------------      ------------- \n");
                for(i=0;i<8;i++)
                {
                   printf("%s         %s       %s            %d %d %d             %d %d %d\n",odaIsimleri[i],odalar[i].isim,odalar[i].soyisim,
                   odalar[i].GtarihGun,odalar[i].GtarihAy,odalar[i].GtarihYil,odalar[i].DtarihGun,odalar[i].DtarihAy,odalar[i].DtarihYil);
                }
                printf("Baska islem yapmak ister misiniz:");
                scanf("%s",&baskaIslem);
                if(strcmp("evet",baskaIslem)==0)
                {
                    goto genelTekrar;
                }
                else
                {
                    break;
                }
                break;
            }
        default:
            {
                printf("Geçerli bir deger giriniz.");
                break;
            }


    }
    return 0;
    }

