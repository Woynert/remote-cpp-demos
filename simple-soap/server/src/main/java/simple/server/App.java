package simple.server;

import javax.xml.ws.Endpoint;
import simple.model.*;
import simple.server.soap.*;

public class App
{
	public static void main (String[] args)
	{
		// add some songs
		System.out.println ("Server: Creating song storage");
		Storage storage = new Storage();

		Song s;
		s = new Song ("Coffee", "Jack Stauber", 59000, 2019);
		storage.addSong (s);
		s = new Song ("Oatmeal", "Jack Stauber", 48000, 2019);
		storage.addSong (s);
		s = new Song ("Milk", "Jack Stauber", 104000, 2019);
		storage.addSong (s);
		s = new Song ("Hope", "Jack Stauber", 27000, 2019);
		storage.addSong (s);

		// serve SOAP

		System.out.println ("Gateway: Starting SOAP");
		Endpoint.publish ("http://0.0.0.0:8080/sampleservice", new SampleServiceImp ());
	}
}
