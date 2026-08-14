class Bai2 {
    public static void main(String[] args) {

    }

    private long countFactors(long n) {
       long total = 1;
       long temp = n;
       for (long i = 2; i * i <= temp; i++) {
           if (temp % i == 0) {
               int a = 0;
               while (temp % i == 0) {
                   a++;
                   temp /= i;
               }
               total *= (a + 1);
           }
       }
       if (temp > 1) total *= 2;
       return total;
    }

}
