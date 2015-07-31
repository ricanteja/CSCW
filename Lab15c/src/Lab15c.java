import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.MouseButton;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Lab15c extends Application
{
    @Override public void start(Stage primaryStage)
    {
        PendulumPane pane = new PendulumPane();

        KeyFrame kf = new KeyFrame(Duration.millis(30), e -> {pane.next();});
        Timeline timeline = new Timeline();
        timeline.getKeyFrames().add(kf);
        timeline.setCycleCount(Timeline.INDEFINITE);
        timeline.play();

        Scene scene = new Scene(pane, 500, 500);

        scene.setOnKeyPressed(e ->
        {
            if(e.getCode() == KeyCode.UP)
            {
                timeline.setRate(timeline.getRate() + 1);
                System.out.println("Rate increased to " + timeline.getRate());
            }
            if(e.getCode() == KeyCode.DOWN)
            {
                timeline.setRate(timeline.getRate() - 1);
                System.out.println("Rate decreased to " + timeline.getRate());
            }
        });

        scene.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
            {
                if(timeline.getStatus() == Timeline.Status.PAUSED)
                    timeline.play();
                else
                    timeline.pause();

                System.out.println("Animation is now " + (timeline.getStatus() == Timeline.Status.PAUSED ? "paused." : "playing."));
            }
        });

        primaryStage.setTitle("Lab15c");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    class PendulumPane extends Pane
    {
        PendulumPane()
        {
            circleTop = new Circle(250, 50, 10);
            circleTop.setFill(Color.BLACK);

            circleBottom = new Circle(250, 350, 50);
            circleBottom.setFill(Color.BLACK);

            lineMiddle = new Line(250, 50, 250, 350);
            lineMiddle.setStroke(Color.BLACK);
            lineMiddle.endXProperty().bind(circleBottom.centerXProperty());
            lineMiddle.endYProperty().bind(circleBottom.centerYProperty());

            this.getChildren().addAll(circleTop, circleBottom, lineMiddle);
        }

        public void next()
        {
            if(flag)
            {
                if(angle > leftAngle)
                    flag = !flag;
                else
                    angle += 1;
            }
            else
            {
                if(angle < rightAngle)
                    flag = !flag;
                else
                    angle -= 1;
            }

            circleBottom.setCenterX(circleTop.getCenterX() + 300 * Math.cos(Math.toRadians(angle)));
            circleBottom.setCenterY(circleTop.getCenterY() + 300 * Math.sin(Math.toRadians(angle)));
        }

        boolean flag = false;
        double angle = 90;
        double leftAngle = 120;
        double rightAngle = 60;

        Circle circleTop;
        Circle circleBottom;
        Line lineMiddle;
    }
}