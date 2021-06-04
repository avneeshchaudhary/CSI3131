public class Fibonacci extends Thread {
    private int position;
    public int answer;
    private int[] sequence;

    public Fibonacci(int position, int[] sequence) {
        this.position = position;
        this.sequence = sequence;
    }

    public void run() {
        if (this.position <= 2) {
            this.answer = 1;
        } else {
            try {
                Fibonacci fib1 = new Fibonacci(position - 1, sequence);
                Fibonacci fib2 = new Fibonacci(position - 2, sequence);
                fib1.start();
                fib2.start();
                fib1.join();
                fib2.join();

                this.answer = fib1.answer + fib2.answer;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        sequence[position] = answer;
    }
}
