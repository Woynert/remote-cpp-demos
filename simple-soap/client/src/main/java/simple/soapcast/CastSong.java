package simple.soapcast;
import simple.model.Song;

public class CastSong
{
	public static Song cast (simple.generated.soap.Song s)
	{
		return new Song (s.getTitle (), s.getAutor (), s.getDuration (), s.getYear ());
	}
}
