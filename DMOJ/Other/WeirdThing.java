import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;

import java.math.BigDecimal;
import java.math.BigInteger;

public class WeirdThing {

    public static void main (String[] args) {
        final BigInteger MAX = new BigInteger("10000000000000000000000000000000000000000000000000000000000000000000000000000000");
        final BigInteger TWO = new BigInteger("2");
        BigInteger N = new BigInteger("75600030383489996993256158996099114210813");
        BigInteger C = new BigInteger("21244279612371424224756594855574909595691");
        BigInteger E = new BigInteger("65537");
        BigInteger P = new BigInteger("274954596949187225233");
        BigInteger Q = new BigInteger("274954596949187225261");

        BigInteger base = N;

        for(int i=0; i<10000000; i++) {
            BigInteger newBase = base.add(C);

            BigInteger max = newBase;
            BigInteger min = BigInteger.ZERO;

            int count = 0;
            while (max.subtract(min).compareTo(BigInteger.ONE) > 0) {
                count ++;
                BigInteger mid = max.add(min).divide(TWO);
                BigInteger power = mid.pow(65537);
                if (power.compareTo(newBase) < 0) {
                    min = mid;
                } else if (power.compareTo(newBase) > 0) {
                    max = mid;
                } else {
                    System.out.println("FOUND!!!");
                    System.out.println(newBase);
                    System.exit(0);
                }
                //System.out.println(min + " " + mid + " " + max);
            }
            System.out.println(count);
            base = base.multiply(N);
        }

        BigInteger M = BigInteger.ONE;

        System.out.println(M);


        String hexStr = M.toString(16);

        StringBuilder output = new StringBuilder();

        for (int i = 0; i < hexStr.length(); i += 2) {
            String str = hexStr.substring(i, i + 2);
            output.append((char) Integer.parseInt(str, 16));
        }

        System.out.println(output.toString());
    }

}
