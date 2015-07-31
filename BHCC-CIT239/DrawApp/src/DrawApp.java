import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.input.MouseButton;
import javafx.scene.layout.*;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.event.EventHandler;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.KeyCode;
import javafx.scene.shape.Line;
import javafx.scene.paint.Color;


public class DrawApp extends Application
{
    @Override public void start(Stage primaryStage)
    {
        BorderPane window = new BorderPane();
        Pane canvas = new Pane();
        VBox toolbar = new VBox(2);

        BrushCursor brush = new BrushCursor();
        InputHandler input = new InputHandler();

        Rectangle boxBlack = new Rectangle(0, 0, 16, 16);
        boxBlack.setFill(Color.BLACK);
        Rectangle boxYellow = new Rectangle(0, 0, 16, 16);
        boxYellow.setFill(Color.YELLOW);
        Rectangle boxOrange = new Rectangle(0, 0, 16, 16);
        boxOrange.setFill(Color.ORANGE);
        Rectangle boxRed = new Rectangle(0, 0, 16, 16);
        boxRed.setFill(Color.RED);
        Rectangle boxPurple = new Rectangle(0, 0, 16, 16);
        boxPurple.setFill(Color.PURPLE);
        Rectangle boxBlue = new Rectangle(0, 0, 16, 16);
        boxBlue.setFill(Color.BLUE);
        Rectangle boxGreen = new Rectangle(0, 0, 16, 16);
        boxGreen.setFill(Color.GREEN);

        toolbar.setAlignment(Pos.TOP_RIGHT);
        toolbar.getChildren().addAll(boxBlack, boxYellow, boxOrange, boxRed, boxPurple, boxBlue, boxGreen);

        window.setRight(toolbar);
        window.setLeft(canvas);

        Scene scene = new Scene(window, 600, 400);

        //Handle all the color box buttons to set the brush color
        boxBlack.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
                brush.color = Color.BLACK;
        });

        boxYellow.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
                brush.color = Color.YELLOW;
        });

        boxOrange.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
                brush.color = Color.ORANGE;
        });

        boxRed.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
                brush.color = Color.RED;
        });

        boxPurple.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
                brush.color = Color.PURPLE;
        });

        boxBlue.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
                brush.color = Color.BLUE;
        });

        boxGreen.setOnMouseClicked(e ->
        {
            if(e.getButton() == MouseButton.PRIMARY)
                brush.color = Color.GREEN;
        });

        //Handle key pressed event and move the cursor to draw
        scene.setOnKeyPressed(e ->
        {
            brush.oldX = brush.newX;
            brush.oldY = brush.newY;

            input.handle(e);

            if(input.upKey)
                brush.newY -= brush.brushSize;
            else if(input.downKey)
                brush.newY += brush.brushSize;
            else if(input.leftKey)
                brush.newX -= brush.brushSize;
            else if(input.rightKey)
                brush.newX += brush.brushSize;
            else if(input.deleteKey)
                canvas.getChildren().clear();

            if(!input.shiftKey && !input.deleteKey)
            {
                Line line = new Line(brush.oldX, brush.oldY, brush.newX, brush.newY);
                line.setStroke(brush.color);

                canvas.getChildren().add(line);
            }

        });

        scene.setOnKeyReleased(input);

        primaryStage.setScene(scene);
        primaryStage.setTitle("DrawApp");
        primaryStage.show();
    }

    class BrushCursor
    {
        int newX = 0;
        int newY = 0;
        int oldX = 0;
        int oldY = 0;
        int brushSize = 15;
        Color color = Color.RED;
    }

    class InputHandler implements EventHandler<KeyEvent>
    {
        @Override public void handle(KeyEvent e)
        {
            KeyCode kc = e.getCode();

            //Handle key pressed/released event for each key
            if(e.getEventType() == KeyEvent.KEY_PRESSED)
            {
                if(kc == KeyCode.UP)
                    upKey = true;
                else if(kc == KeyCode.DOWN)
                    downKey = true;
                else if(kc == KeyCode.LEFT)
                    leftKey = true;
                else if(kc == KeyCode.RIGHT)
                    rightKey = true;
                else if(kc == KeyCode.DELETE)
                    deleteKey = true;

                if(kc == KeyCode.SHIFT)
                    shiftKey = true;
            }
            if(e.getEventType() == KeyEvent.KEY_RELEASED)
            {
                if(kc == KeyCode.UP)
                    upKey = false;
                else if(kc == KeyCode.DOWN)
                    downKey = false;
                else if(kc == KeyCode.LEFT)
                    leftKey = false;
                else if(kc == KeyCode.RIGHT)
                    rightKey = false;
                else if(kc == KeyCode.DELETE)
                    deleteKey = false;

                if(kc == KeyCode.SHIFT)
                    shiftKey = false;
            }
        }

        //Boolean flags for key presses
        boolean shiftKey = false;
        boolean upKey = false;
        boolean downKey = false;
        boolean leftKey = false;
        boolean rightKey = false;
        boolean deleteKey = false;
    }

    /** Main Function**/
    public static void main(String[] args)
    {
        Application.launch(args);
    }
}