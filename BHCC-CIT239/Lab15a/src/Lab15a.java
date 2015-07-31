import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import javafx.scene.Scene;

public class Lab15a extends Application
{
    @Override public void start(Stage primaryStage)
    {
        FlowPane numInputPane = new FlowPane();

        testEvents(primaryStage);
    }

    public static void testEvents(Stage primaryStage)
    {
        HBox pane = new HBox(100);
        pane.setAlignment(Pos.CENTER);

        Button btOK = new Button("OK");
        Button btCancel = new Button("Cancel");

        btOK.setOnAction(e -> { System.out.println("OK Button clicked"); });
        btCancel.setOnAction(e -> { System.out.println("Cancel Button clicked"); });

        pane.getChildren().addAll(btOK, btCancel);

        Scene scene = new Scene(pane);
        primaryStage.setTitle("Handle Events");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}