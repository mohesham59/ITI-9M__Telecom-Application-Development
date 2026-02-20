import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DateTimeGui {
    public static void main(String[] args) {

        JFrame frame = new JFrame();

        frame.setTitle("Hello From Frame");
        frame.setSize(500, 500);
        frame.setVisible(true);

        MyPanel myPanel = new MyPanel();
        frame.setContentPane(myPanel);

        new Thread(myPanel).start();
    }
}

class MyPanel extends JPanel implements Runnable{

    public MyPanel () {
        this.setBackground(Color.LIGHT_GRAY);
    }

    @Override
    public void paintComponent (Graphics g) {
        super.paintComponent(g);
        g.drawString(new Date().toLocaleString(), 180, 200);
    }

    @Override
    public void run () {
        while (true)
        {
            try {
                this.repaint();
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(MyPanel.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}