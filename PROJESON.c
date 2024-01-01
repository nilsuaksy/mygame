#include <stdio.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50

int main()
{
    int startup, gender, characterClass, confirm, todo, enemy, exp = 0, expRequirement = 100, stat, statpointstr = 1, statpointagi = 1, statpointint = 1, statpointluck = 1;
    float maxhealth = 100.00;
    double attackpower = 5.0;
    char name[MAX_NAME_LENGTH];

    printf("Oyunumuza hoşgeldiniz!\n");
    sleep(3);
    printf("\nOyunumuza giriş yapabilmek için lütfen bekleyiniz...\n");
    sleep(3);
    printf("\nOyun başlıyor!\n");
    sleep(1);

    do
    {
        int level = 1;
        printf("1-Karakter Yarat\n2-Oyundan Çıkış Yap\n");
        scanf("%d", &startup);

        if (startup == 1)
        {
            printf("Karakter yaratma ekranına yönlendiriliyorsunuz.\n");
            sleep(3);
            printf("Karakter Adı: ");
            scanf("%s", name);

            printf("Oyuncu %s, lütfen karakterinizin cinsiyetini seçiniz:\n", name);
            sleep(2);
            printf("1-Erkek\n2-Kadın\n");
            scanf("%d", &gender);

            if (gender != 1 && gender != 2)
            {
                printf("Geçersiz cinsiyet seçimi. Lütfen 1 ya da 2 giriniz.\n");
                continue;
            }

            printf("Oyuncu %s, lütfen karakter sınıfınızı seçiniz:\n", name);
            sleep(2);
            printf("1-Savaşçı\n2-Suikastçi\n3-Büyücü\n");
            scanf("%d", &characterClass);

            if (characterClass < 1 || characterClass > 3)
            {
                printf("Geçersiz karakter sınıfı seçimi. Lütfen 1, 2 ya da 3 giriniz.\n");
                continue;
            }

            printf("Oyuncu adınız: %s, karakter cinsiyetiniz: %s, seçtiğiniz karakter sınıfı: ", name, (gender == 1) ? "Erkek" : "Kadın");

            switch (characterClass)
            {
            case 1:
                printf("Savaşçı");
                break;
            case 2:
                printf("Suikastçi");
                break;
            case 3:
                printf("Büyücü");
                break;
            default:
                printf("Bilinmeyen sınıf");
                break;
            }

            printf(". Onaylıyor musunuz?\n");

            sleep(2);
            printf("1-Onaylıyorum\n2-Onaylamıyorum\n");
            scanf("%d", &confirm);

            if (confirm == 1)
            {
                printf("Seçiminiz kaydedildi.\n");
                sleep(3);
                printf("\nOyuna başlıyorsunuz!\n\n");
                sleep(3);
                printf("Oyunumuzda şu anlık yapabileceğiniz şeyler sınırlıdır.\n");
                sleep(2);
                printf("Tam sürüm çıktıktan sonra oyunumuza ek birçok içerik gelecektir.\n");
                sleep(2);
                printf("Şu anda oyunumuzda olan içerikler:\n");
                sleep(2);
                
                for (;;)
                {
                    printf("1-Savaş\n2-Karakter bilgileri\n3-Karakter puanları\n4-Ana ekrana dön\n");
                    scanf("%d", &todo);

                    if (todo == 1)
                    {
                        printf("Saldırmak istediğiniz düşmanı seçiniz:\n");
                        sleep(2);
                        printf("\n1-Sümüklü Anka(50 EXP)\n2-Uyuyan Panda(45 EXP)\n3-Yuvarlanan Sinek(10 EXP)\n4-Ağlayan Koala(5 EXP)\n5-Havlayan Kedi(20 EXP)\n");
                        scanf("%d", &enemy);

                        if (enemy >= 1 && enemy <= 5)
                        {
                            switch (enemy)
                            {
                            case 1:
                                exp += 50;
                                break;
                            case 2:
                                exp += 45;
                                break;
                            case 3:
                                exp += 10;
                                break;
                            case 4:
                                exp += 5;
                                break;
                            case 5:
                                exp += 20;
                                break;
                            }

                            printf("Tebrikler, Toplam EXP: %d\n", exp);
                            if (exp >= expRequirement)
                            {
                                level++;
                                printf("Tebrikler, level atladınız! Yeni seviye: %d\n", level);
                                exp -= expRequirement;
                                expRequirement += 10;
                            }
                        }
                        else
                        {
                            printf("Geçersiz düşman seçimi\n");
                        }
                    }
                    else if (todo == 2)
                    {
                        printf("Karakter adı: %s\n", name);
                        printf("Karakter cinsiyeti: %s\n", (gender == 1) ? "Erkek" : "Kadın");
                        printf("Karakter sınıfı: ");

                        switch (characterClass)
                        {
                        case 1:
                            printf("Savaşçı");
                            break;
                        case 2:
                            printf("Suikastçi");
                            break;
                        case 3:
                            printf("Büyücü");
                            break;
                        default:
                            printf("Bilinmeyen sınıf");
                            break;
                        }

                        printf("\nSeviye: %d\n", level);
                        printf("Bir sonraki seviyeye geçmek için gereken EXP: %d\n", expRequirement);
                        printf("Şu anki EXP'iniz: %d\n\n", exp);
                        printf("Başlangıç canı: %.2f\n", maxhealth);
                        printf("Saldırı Gücü: %.2lf\n", attackpower);
                    }
                    else if (todo == 3)
                    {
                        printf("Verilebilecek karakter puanınız: %d\n1-Güç (%d)\n2-Çeviklik (%d)\n3-Zeka (%d)\n4-Şans (%d)\n", (level - 1), statpointstr, statpointagi, statpointint, statpointluck);

                        if (level > 1)
                        {
                            printf("Karakter puanı vermek istediğiniz stat'ı seçiniz:\n");
                            scanf("%d", &stat);

                            if (stat >= 1 && stat <= 4)
                            {
                                switch (stat)
                                {
                                case 1:
                                    statpointstr += 1;
                                    attackpower += 5.0;
                                    break;
                                case 2:
                                    statpointagi += 1;
                                    break;
                                case 3:
                                    statpointint += 1;
                                    maxhealth += 10.0;
                                    break;
                                case 4:
                                    statpointluck += 1;
                                    break;
                                default:
                                    printf("Geçersiz tuşlama.\n");
                                    break;
                                }
                                printf("Karakteriniz geliştirildi.\n");
                            }
                            else
                            {
                                printf("Geçersiz tuşlama.\n");
                            }
                        }
                        else
                        {
                            printf("Yetersiz karakter puanı. Level atlayarak puan kazanın!\n");
                        }
                    }
                    else if (todo == 4)
                    {
                        printf("Ana ekrana dönüyorsunuz...\n");
                        sleep(3);
                        printf("\nAna ekrana döndünüz.\n");
                        break;
                    }
                    else
                    {
                        printf("Geçersiz seçim\n");
                    }
                    printf("\n");
                    sleep(2);
                }
            }
            else if (confirm == 2)
            {
                printf("Karakter seçiminiz iptal edildi.\n");
                continue;
            }
            else
            {
                printf("Geçersiz tuşlama. Lütfen tekrar seçim yapınız.\n");
                continue;
            }
        }
        else if (startup == 2)
        {
            printf("Çıkış yapılıyor...\n");
            sleep(3);
            printf("\nÇıkış yaptınız.\n");
            break;
        }
        else if (startup != 1 && startup != 2)
        {
            printf("Geçersiz tuşlama. Lütfen tekrar seçim yapınız.\n");
            continue;
        }
        else
        {
            printf("Geçersiz tuşlama. Lütfen tekrar seçim yapınız.\n");
        }

    } while (1);

    return 0;
}
