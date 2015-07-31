import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class Lab14a extends Application
{
    @Override public void start(Stage primaryStage)
    {
        Pane pane = new Pane();
        double paneWidth = 200;
        double paneHeight = 200;
        double width = paneWidth * 0.90 - 30;
        double height = paneHeight * 0.90 - 60;

        Rectangle r1 = new Rectangle(10, 60, width, height);
        Rectangle r2 = new Rectangle(30, 10, width, height);

        Line line1 = new Line();
        Line line2 = new Line();
        Line line3 = new Line();
        Line line4 = new Line();

        r1.setFill(new Color(1, 1, 1, 0));
        r1.setStroke(Color.BLACK);
        r2.setFill(new Color(1, 1, 1, 0));
        r2.setStroke(Color.BLACK);

        line1.setStartX(10);
        line1.setEndX(30);
        line1.setStartY(60);
        line1.setEndY(10);

        line2.setStartX(10 + width);
        line2.setEndX(30 + width);
        line2.setStartY(60);
        line2.setEndY(10);

        line3.setStartX(10);
        line3.setEndX(30);
        line3.setStartY(60 + height);
        line3.setEndY(10 + height);

        line4.setStartX(10 + width);
        line4.setEndX(30 + width);
        line4.setStartY(60 + height);
        line4.setEndY(10 + height);

        pane.getChildren().add(r1);
        pane.getChildren().add(r2);
        pane.getChildren().add(line1);
        pane.getChildren().add(line2);
        pane.getChildren().add(line3);
        pane.getChildren().add(line4);

        Scene scene = new Scene(pane, paneWidth, paneHeight);
        primaryStage.setTitle("Lab14a");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args)
    {
        launch(args);
    }
}