import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.geometry.Pos;


public class Lab16a extends Application
{
    @Override public void start(Stage primaryStage)
    {
        BorderPane mainPane = new BorderPane();

        FlowPane topPane = new FlowPane();
        topPane.setAlignment(Pos.CENTER);

        FlowPane bottomPane = new FlowPane(8, 0);
        bottomPane.setAlignment(Pos.CENTER);

        TextField tfString = new TextField();
        tfString.prefColumnCountProperty().set(24);
        TextField tfColumn = new TextField();
        tfColumn.prefColumnCountProperty().set(3);

        RadioButton radBtLeft = new RadioButton("Left");
        RadioButton radBtCenter = new RadioButton("Center");
        RadioButton radBtRight = new RadioButton("Right");

        ToggleGroup toggleGroup = new ToggleGroup();

        radBtLeft.toggleGroupProperty().set(toggleGroup);
        radBtRight.toggleGroupProperty().set(toggleGroup);
        radBtCenter.toggleGroupProperty().set(toggleGroup);

        topPane.getChildren().addAll(new Label("Text Field"), tfString);
        bottomPane.getChildren().addAll(radBtLeft, radBtCenter, radBtRight, new Label("      Column Size"), tfColumn);

        mainPane.setTop(topPane);
        mainPane.setBottom(bottomPane);

        Scene scene = new Scene(mainPane);

        radBtLeft.setOnAction(e ->
        {
            tfString.alignmentProperty().set(Pos.CENTER_LEFT);
        });
        radBtCenter.setOnAction(e ->
        {
            tfString.alignmentProperty().set(Pos.CENTER);
        });
        radBtRight.setOnAction(e ->
        {
            tfString.alignmentProperty().set(Pos.CENTER_RIGHT);
        });
        tfColumn.setOnAction(e ->
        {
            tfString.setPrefColumnCount(Integer.parseInt(tfColumn.getText()));
            tfColumn.setText("");
        });

        primaryStage.setScene(scene);
        primaryStage.setTitle("Lab16a");
        primaryStage.show();
    }

    public static void main(String[] args)
    {
        Application.launch(args);
    }
}