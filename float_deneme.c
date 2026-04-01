#include <stdio.h>
#include <stdlib.h>

static int	ft_get_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_get_len(nbr);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

int main()
{
    // Derleyicinin optimizasyon yapmasını yasaklıyoruz
    volatile float a = 4993.0f;
    volatile float b = 10000.0f;
    
    float sonuc;

    sonuc = a / b;              // 0.4993 (Ama bellekte 0.4992999...)
    sonuc = sonuc * 10000.0f;   // 4992.999... (10000 ile çarptık ki virgülden kurtulsun)
    
    printf("Matematikte Beklenen : 4993\n");
    printf("C'nin Gercek Ciktisi : %s\n", ft_itoa(sonuc)); // ft_itoa virgülden sonrasını kesecek!
    
    return 0;
}