package simple.server.soap;

import simple.model.*;
import javax.jws.WebMethod;
import javax.jws.WebService;

@WebService
public interface SampleService {
	@WebMethod int getSongAmount ();

	@WebMethod Song getSongById (int songId);

	//@WebMethod Storage (int fileId, String newName);

	//@WebMethod boolean deleteFile (int fileId);
}
