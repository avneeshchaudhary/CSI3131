import java.util.ArrayList;

public class Main {
    public static int parseArg(String[] args) throws Exception {
        if (args.length == 0) {
            throw new Exception("Program requires number argument");
        }

        return Integer.parseInt(args[0]);
    }

    public static void main(String[] args) {
        try {
            int position = Main.parseArg(args);
            int size = position + 1;

            int[] sequence = new int[size];
            sequence[0] = 0;
            sequence[1] = 1;

            Fibonacci fib = new Fibonacci(position, sequence);
            fib.start();
            fib.join();

            for (int i = 0; i < size; i++) {
                System.out.println(sequence[i]);
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
