// Assignment 12: Arizona State University CSE205
//         Name: Your Name
//    StudentID: Your ID
//      Lecture: Your lecture time
//  Description: 


public class WaveDisplayPane extends Pane {

	// Task #1: immplement instance variables, constructor, and methods
	// as outlned in the UML diagram and assignment description








	// defines an event listener to draw a new point
	private class WaveHandler implements EventHandler<ActionEvent> {
		public void handle(ActionEvent event) {
			time++;
			int x = (waveLength * time) / 314;
			int y = (int) (waveAmplitude * Math.sin((0.0174533) * time) + 115);

			if (x < paneWidth) {
				Circle dot = new Circle(x, y, 2);
				dot.setFill(color);
				getChildren().add(dot);
			} else suspend();
		}
	}
}
