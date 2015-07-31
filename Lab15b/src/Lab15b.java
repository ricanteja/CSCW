import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.scene.Node;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.input.MouseButton;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;
import javafx.scene.paint.Color;


public class Lab15b extends Application
{
    @Override public void start(Stage primaryStage)
    {
        Pane pane = new Pane();
        pane.setPrefSize(480, 320);

        pane.setOnMouseClicked(e ->
        {
            if(e.getButton().equals(MouseButton.PRIMARY))
            {
                Circle circle = new Circle(5);
                circle.setStroke(Color.BLACK);
                circle.setFill(Color.AQUA);
                circle.setCenterX(e.getX());
                circle.setCenterY(e.getY());

                pane.getChildren().add(circle);

                System.out.printf("Adding point at x=%6.1f, y=%6.1f\n", e.getX(), e.getY());
            }
            if(e.getButton().equals(MouseButton.SECONDARY))
            {
                ObservableList<Node> list = pane.getChildren();

                for(int i = 0; i < list.size(); i++)
                {
                    if(list.get(i).contains(e.getX(), e.getY()))
                    {
                        pane.getChildren().remove(i);
                        System.out.printf("Removing point at x=%6.1f, y=%6.1f\n", e.getX(), e.getY());
                        break;
                    }
                }
            }
        });

        Scene scene = new Scene(pane);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Lab15b");
        primaryStage.show();
    }
}