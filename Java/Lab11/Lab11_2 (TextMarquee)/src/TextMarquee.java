import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

public class TextMarquee {
    public static void main (String[] args) {

        JFrame frame = new JFrame();

        frame.setTitle("Texr Marquee  From Frame");
        frame.setSize(500,300);
        frame.setVisible(true);

        MyPanel panel = new MyPanel();
        frame.setContentPane(panel);

        new Thread(panel).start();
    }
}

class MyPanel extends JPanel implements Runnable {
    int x = 160;
    public MyPanel(){
        this.setBackground(Color.lightGray);
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawString("Hello From My Panel  ^_^", x, 125);
    }

    @Override
    public void run() {
        while (true)
        {
            x+=15;
            if(x>500) {
                x = -100;
            }
            this.repaint();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();            }
        }
    }
}
