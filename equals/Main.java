import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main
{
    public static void main(
            String[] args) throws Exception
    {
        BufferedReader buffer =
            new BufferedReader(
                new InputStreamReader(System.in));

        String s = buffer.readLine();
        String n = buffer.readLine();
        if (s.equals(n)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        buffer.close();
    }
}
