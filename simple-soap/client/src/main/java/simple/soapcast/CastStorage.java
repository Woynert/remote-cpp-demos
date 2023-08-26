package simple.soapcast;
import simple.model.*;

public class CastStorage
{
	public static Storage cast (simple.generated.soap.Storage s)
	{
		Storage storage = new Storage ();
		Song song;

		for (simple.generated.soap.Song isong : s.getSongs ()) {
			song = CastSong.cast (isong);
			storage.addSong (song);
		}

		return storage;
	}
}
