package datastore;

import java.io.File;

public class CheckupTmpFileHandler {
	
	private static final String CHECKUP_TMP_PATH = "datastore/checkup.tmp";

	public void createcheckupTmp() {
		File checkupTmpFile = new File(CHECKUP_TMP_PATH);
		if (!checkupTmpFile) {
			
		}
		
	}

}
