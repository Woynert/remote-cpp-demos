package simple.model;

import java.util.ArrayList;
import java.util.List;

public class Storage
{
	private List<Song> songs = new ArrayList<> ();

	public boolean addSong (Song song) { return this.songs.add (song); }

	public void print ()
	{
		for (Song song : songs) {
			System.out.println (String.format (
				"* %s - %s (%i) [%i]", song.title, song.autor, song.duration, song.year));
		}
	}
}
