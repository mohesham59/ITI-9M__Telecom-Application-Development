import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;

public class BouncingBall {
    public static void main (String[] args) {

        JFrame frame = new JFrame();

        frame.setTitle("Bouncing Ball Application");
        frame.setSize(500,500);
        frame.setVisible(true);

        MyPanel panel = new MyPanel();
        frame.setContentPane(panel);

        new Thread(panel).start();
    }
}

class MyPanel extends JPanel implements Runnable {
    int x = 100;
    int y = 100;

    int dx = 5;
    int dy = 5;

    int ballSize = 20;
;

    public MyPanel(){
        this.setBackground(Color.cyan);
    }

    @Override
    public void paintComponent (Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.red);
        g.fillOval(x, y, ballSize, ballSize);
    }

    @Override
    public void run() {
        while (true)
        {
            // Update ball position
            x += dx;
            y += dy;

            // Reverse horizontal direction if ball hits left or right wall
            if (x <= 0 || x >= getWidth() - ballSize) {
                dx = -dx;
            }

            // Reverse vertical direction if ball hits top or bottom wall
            if (y <= 0 || y >= getHeight() - ballSize) {
                dy = -dy;
            }

            try {
                this.repaint();
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}