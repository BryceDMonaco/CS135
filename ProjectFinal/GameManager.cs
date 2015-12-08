/*
    Author: Bryce Monaco
    Created: 11/14/15
    Last Modified: 12/6/15

    This script handles the entire game, from spawning the boxes to assigning the target to keeping the score

    This script has loops and decisions throughout
*/

using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class GameManager : MonoBehaviour {
    public int gameDifficulty = 1; //0-2, changes amount of fakes
    public Transform[] respawnPoints;
    public GameObject[] gameBoxes;
    public Transform startPoint; //Where all boxes are spawned on game start
    public GameObject boxPrefab; //Prefab to spawn at startPoint
    public GameObject[] modelBox = new GameObject[9];
    public int currentScore = 0;
    public int highScore = 0;
    public float gameTime;
    private float startTime;
    public bool trackTime = false;

    //UI Variables
    public Text startTimer;
    public GameObject startPanel;
    public Text timerText;

    public Text scoreText;
    public Text highScoreText;

    public Button pauseButton;
    public GameObject pausePanel;

    public GameObject gameoverPanel;

    // Use this for initialization
    void Start () {

        if (Application.platform != RuntimePlatform.Android)
        {
            UnityEngine.Screen.SetResolution(331, 589, false);

        }

        Time.timeScale = 1.0f;
        pauseButton.interactable = false;

        if (!PlayerPrefs.HasKey("HighScore"))
        {
            PlayerPrefs.SetInt("HighScore", 0);

        }

        highScore = PlayerPrefs.GetInt("HighScore");
        highScoreText.text = ("Best: " + highScore);
        scoreText.text = ("Score: " + currentScore);

        //This block finds all gameobjects that are respawn points, then stores their transform component
        GameObject[] rPointGO; //Stands for Respawn Point GameObject
        rPointGO = GameObject.FindGameObjectsWithTag("Respawn");

        respawnPoints = new Transform[rPointGO.Length];

        for (int i = 0; i < rPointGO.Length; i++)
        {
            respawnPoints[i] = rPointGO[i].transform;
        }

        int spawnCount = 0;

        switch (gameDifficulty)
        {
            case 0:
                spawnCount = 5;

                break;

            case 1:
                spawnCount = 8;

                break;

            case 2:
                spawnCount = 10;

                break;
        }

        for (int i = 0; i < spawnCount; i++)
        {
            GameObject.Instantiate(boxPrefab , respawnPoints[Random.Range(0, (respawnPoints.Length - 1))].position, Quaternion.identity);
        }

        gameBoxes = GameObject.FindGameObjectsWithTag("Box");

        int targetBox = Random.Range(0, (gameBoxes.Length - 1));

        for (int i = 0; i < gameBoxes.Length; i++)
        {
            if (i == targetBox)
            {
                gameBoxes[i].GetComponent<BoxGen>().isTarget = true;
                gameBoxes[i].GetComponent<BoxGen>().RespawnBox(false);
                gameBoxes[i].name = "TARGET";

            }
            else
            {
                gameBoxes[i].GetComponent<BoxGen>().RespawnBox(true);

            }
        }
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    private int timerKeeper = 0;

    //Called every 0.02 seconds regardless of if a frame has been drawn yet
    void FixedUpdate ()
    {
        timerKeeper++;
        
        switch (timerKeeper)
        {
            case 0:
                startTimer.text = "3";

                break;

            case 50:
                startTimer.text = "2";

                break;

            case 100:
                startTimer.text = "1";

                break;

            case 150:
                startTimer.text = "GO";

                break;

            case 175:
                startPanel.SetActive(false);
                pauseButton.interactable = true;

                Time.timeScale = 1.0f;

                trackTime = true;

                startTime = Time.time;

                break;
        }
        
        if (trackTime)
        {
            gameTime = 30 - (Time.time - startTime) + (currentScore * 2);

            if (gameTime <= 0.0f)
            {
                gameTime = 0.0000f;

                GameOver();

            }

            timerText.text = gameTime.ToString("0.0");


        }
    }

    public void CheckTargetSeed (int[] seed)
    {
        for (int i = 0; i < 9; i++)
        {
            if (seed[i] == 0)
            {
                modelBox[i].GetComponent<Image>().enabled = false;

            } else if (seed[i] == 1)
            {
                modelBox[i].GetComponent<Image>().enabled = true;

            }
        }
    }

    public void UpdateGameScore (int amount)
    {
        currentScore += amount;

        if (currentScore > 0)
        {
            scoreText.text = ("Score: " + currentScore);

        } else if (currentScore <= 0)
        {
            scoreText.text = "Score: 0";

        }

        if (currentScore > highScore)
        {
            highScore = currentScore;

            PlayerPrefs.SetInt("HighScore", highScore);

            highScoreText.text = ("Best: " + highScore);
        }
    }

    public void PauseGame (int state) //0 unpause, 1 pause
    {
        switch (state)
        {
            case 0: //Unpause
                Time.timeScale = 1.0f;
                pauseButton.interactable = true;

                pausePanel.SetActive(false);

                break;

            case 1: //Pause
                Time.timeScale = 0.0f;
                pauseButton.interactable = false;

                pausePanel.SetActive(true);

                break;

        }

    }

    public void RestartGame ()
    {
        Application.LoadLevel("TestScene");

    }

    public void GameOver ()
    {
        gameoverPanel.SetActive(true);

        gameoverPanel.transform.FindChild("Text_Score").GetComponent<Text>().text = "Score:\n" + currentScore;
        gameoverPanel.transform.FindChild("Text_HighScore").GetComponent<Text>().text = "High Score:\n" + highScore;

        Time.timeScale = 0.0f;

    }

    public void ApplyModelColor (Color setColor)
    {
        setColor.a = 255;

        for (int i = 0; i < 9; i++)
        {
            modelBox[i].GetComponent<Image>().color = setColor;

        }
    }
}
